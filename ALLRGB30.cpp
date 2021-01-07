#include <fstream>
#include <cstdlib>
#define DIM 32768 
using namespace std;
ofstream fcout;
unsigned short RD(int i,int j){
	return (i%1024)*64;
}
unsigned short GR(int i,int j){
	return (j%1024)*64;
}
unsigned short BL(int i,int j){
	return ((i/1024)+32*(j/1024))*64;
}
void pixel_write(int i, int j){
    static unsigned short color[3];
    static unsigned char color_1st_byte[3],color_2nd_byte[3];
    color[0] = RD(i,j);
    color[1] = GR(i,j);
    color[2] = BL(i,j);
    for(int i=0;i<3;i++){
		color_1st_byte[i]=color[i]/256;
		color_2nd_byte[i]=color[i]%256;
		fcout<<color_1st_byte[i]<<color_2nd_byte[i];
	}
}
int main(){
	fcout.open("ALLRGB30.ppm",ios::binary);
	fcout<<"P6\n"<<DIM<<" "<<DIM<<"\n65535\n";
    for(int j=0;j<DIM;j++)
    {	printf("row: %d\n",j);
        for(int i=0;i<DIM;i++)
            pixel_write(i,j);}
    fcout.close();
    return 0;
}
