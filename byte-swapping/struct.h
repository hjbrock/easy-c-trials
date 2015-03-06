struct s1 {
  unsigned long long f0;
  long f1;
  unsigned char f2;
  int f3;
  short f4;
  unsigned long f5;
};

struct s2 {
  unsigned int f0;
  short f1;
  short f2;
  int f3;
  short f4;
  long long f5;
};

#pragma pack (1)
struct s2_packed {
  unsigned int f0;
  short f1;
  short f2;
  int f3;
  short f4;
  long long f5;
};
#pragma pack ()

struct s3 {
  short f0;
  char f1;
  signed char f2;
  unsigned long long f3;
  unsigned int f4;
  char f5;
};

struct s3_bitfield {
  short f0 : 14;
  char f1 : 8;
  signed char f2 : 2;
  unsigned long long f3 : 49;
  unsigned int f4 : 2;
  char f5 : 6;
};

