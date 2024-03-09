#include <stdio.h>
//Struct
struct Mahasiswa
{
    const char *name;
    const char *address;
    int age;
};
int main()
{
    struct Mahasiswa mhs1, mhs2;
    mhs1.name = "Munib";
    mhs1.address = "jambi";
    mhs1.age = 22;
    mhs2.name = "sudol";
    mhs2.address = "akherat";
    mhs2.age = 23;
    printf("## Mahasiswa 1 ##\n");
    printf("Nama: %s\n", mhs1.name);
    printf("Alamat: %s\n", mhs1.address);
    printf("Umur: %d\n", mhs1.age);
    printf("## Mahasiswa 2 ##\n");
    printf("Nama: %s\n", mhs2.name);
    printf("Alamat: %s\n", mhs2.address);
    printf("Umur: %d\n", mhs2.age);
return 0;
}