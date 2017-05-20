#include "md5encrypter.h"

void md5_encrypt(char *str)
{
  uint32_t V[] = { v[0] , v[1], v[2], v[3] };
  uint32_t f = 0;
  uint32_t g = 0;
  size_t len_str = strlen(str);
  int len = 0;
  for(int i = (len_str * 8) + 1; len % 512 != 448; i++)
    {
      len = i;
    }
  len /= 8; 
  char *msg = (char *)calloc(len + 64, 1);
  if (!msg)
    return;
  memcpy(msg , str, len_str);
  msg[len_str] = (char)0x80;
  uint32_t bits_len = 8 * len_str;
  memcpy(msg + len, &bits_len, 4);
  for(int i = 0; i < len; i += 64) 
    {
      uint32_t *s = (uint32_t *) (msg + i);
      for (int j = 0; j < 64; j++)
	{
	  if (j <= 15)
	    {
	      f = F(V[1], V[2], V[3]);
	      g = j;
	    }
	  else if (j <= 31)
	    {
	      f = G(V[1], V[2], V[3]);
	      g = (5 * j + 1) % 16;
	    }
	  else if (j <= 47)
	    {
	      f = H(V[1], V[2], V[3]);
	      g = (3 * j + 5) % 16;
	    }
	  else
	    {
	      f = I(V[1], V[2], V[3]);
	      g = (7 * j) % 16;
	    }
	  uint32_t tmp = V[3];
	  V[3] = V[2];
	  V[2] = V[1];
	  V[1] += ROTATION((V[0] + f + k[j] + s[g]), r[j]);
	  V[0] = tmp;
	}
      for (int j = 0; j < 4; j++)
	v[j] += V[j];
    }
  if (msg)
    free(msg);
}

int main(int argc, char *argv[])
{
  if (argc != 2)
    {
      printf("[USAGE] : \"./md5 'your_string'\"\n ");
      return 0;
    }
  md5_encrypt(argv[1]);
  uint32_t tab[] = {v[0], v[1], v[2] , v[3]};
  uint8_t *p;
  for (int i = 0; i < 4; i++)
    {
      p=(uint8_t *)&tab[i];
      for (int j = 0; j < 4; j++)
	printf("%2.2x", p[j]);
    }
  puts("\n");
  return 1; 
}
