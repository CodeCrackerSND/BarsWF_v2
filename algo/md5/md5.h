#pragma once

#define S11 7
#define S12 12
#define S13 17
#define S14 22
#define S21 5
#define S22 9
#define S23 14
#define S24 20
#define S31 4
#define S32 11
#define S33 16
#define S34 23
#define S41 6
#define S42 10
#define S43 15
#define S44 21

/* F, G, H and I are basic MD5 functions. */

#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))

//#define ROTATE_LEFT(x, n) ((((unsigned int)x) << ((unsigned int)(n))) | (((unsigned int)x) >> ((unsigned int)(32-(n)))))

#define ROTATE_LEFT(x, n) ((((unsigned int)x) << ((unsigned int)(n))) + (((unsigned int)x) >> ((unsigned int)(32-(n)))))


#define DO(step,a, b, c, d, x, s, ac) (a) += (x+ac) + step ((b), (c), (d));(a) = ROTATE_LEFT ((a), (s))+(unsigned int)b;
#define unrollII(a, b, c, d, x, s, ac) (a) -= (b);(a) = ROTATE_LEFT ((a), (32-s));(a) -= I ((b), (c), (d)) + (x) + (ac);

#define DO_NoData(step,a, b, c, d, x, s, ac) (a) += ac + step ((b), (c), (d));(a) = ROTATE_LEFT ((a), (s))+(unsigned int)b;

#define FF2(a, b, c, d, x, s, ac, ic,id) { DO(F,a,b,c,d,x,s,ac);}
#define GG2(a, b, c, d, x, s, ac, ic,id) { DO(G,a,b,c,d,x,s,ac);}
#define HH2(a, b, c, d, x, s, ac, ic,id) { DO(H,a,b,c,d,x,s,ac);}
#define II2(a, b, c, d, x, s, ac, ic,id) { DO(I,a,b,c,d,x,s,ac);}

#define FF2_NoData(a, b, c, d, x, s, ac, ic,id) { DO_NoData(F,a,b,c,d,x,s,ac);}
#define GG2_NoData(a, b, c, d, x, s, ac, ic,id) { DO_NoData(G,a,b,c,d,x,s,ac);}
#define HH2_NoData(a, b, c, d, x, s, ac, ic,id) { DO_NoData(H,a,b,c,d,x,s,ac);}
#define II2_NoData(a, b, c, d, x, s, ac, ic,id) { DO_NoData(I,a,b,c,d,x,s,ac);}

#define DO_3(op,a, b, c, d, x, s, ac, ic,id) { DO(op,a##1,b##1,c##1,d##1,x##1,s,ac);DO(op,a##2,b##2,c##2,d##2,x##2,s,ac);DO(op,a##3,b##3,c##3,d##3,x##3,s,ac);}
#define DO_4(op,a, b, c, d, x, s, ac, ic,id) { DO(op,a##1,b##1,c##1,d##1,x##1,s,ac);DO(op,a##2,b##2,c##2,d##2,x##2,s,ac);DO(op,a##3,b##3,c##3,d##3,x##3,s,ac);DO(op,a##4,b##4,c##4,d##4,x##4,s,ac);}
#define DO_5(op,a, b, c, d, x, s, ac, ic,id) { DO(op,a##1,b##1,c##1,d##1,x##1,s,ac);DO(op,a##2,b##2,c##2,d##2,x##2,s,ac);DO(op,a##3,b##3,c##3,d##3,x##3,s,ac);DO(op,a##4,b##4,c##4,d##4,x##4,s,ac);DO(op,a##5,b##5,c##5,d##5,x##5,s,ac);}
#define DO_6(op,a, b, c, d, x, s, ac, ic,id) { DO(op,a##1,b##1,c##1,d##1,x##1,s,ac);DO(op,a##2,b##2,c##2,d##2,x##2,s,ac);DO(op,a##3,b##3,c##3,d##3,x##3,s,ac);DO(op,a##4,b##4,c##4,d##4,x##4,s,ac);DO(op,a##5,b##5,c##5,d##5,x##5,s,ac);DO(op,a##6,b##6,c##6,d##6,x##6,s,ac);}

#define UL_5(a, b, c, d, x, s, ac, ic,id) { unrollII(a##1,b##1,c##1,d##1,x##1,s,ac);unrollII(a##2,b##2,c##2,d##2,x##2,s,ac);unrollII(a##3,b##3,c##3,d##3,x##3,s,ac);unrollII(a##4,b##4,c##4,d##4,x##4,s,ac);unrollII(a##5,b##5,c##5,d##5,x##5,s,ac);}

// optimization 2 https://hashcat.net/events/p13/js-ocohaaaa.pdf
#define FF2_first(a, b, c, d, x, s, ac, ic,id) (a) += (x+ac);(a) = ROTATE_LEFT ((a), (s))+(unsigned int)b;
