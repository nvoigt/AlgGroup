#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <utime.h>
#include <string.h>
#include <dirent.h>
#include <math.h>
#include <sys/un.h>

#define LINENUM 100


int main(){

// Current length of sub array or visible lines
 int curr_sub;
 int i, j, k, ii;
 int m[LINENUM] = {-980, -979, -891, -887, -858, -845, -782, -759, -757, -731, -711, -700, -678, -671, -650, -569, -553, -549, -538, -528, -519, -490, -460, -455, -447, -446, -442, -409, -398, -354, -348, -338, -278, -273, -272, -237, -227, -209, -196, -188, -138, -120, -119, -103, -70, -56, -53, -37, -29, -22, -17, 16, 20, 43, 80, 97, 112, 134, 171, 204, 219, 222, 245, 277, 295, 332, 341, 407, 433, 435, 468, 472, 478, 481, 509, 519, 520, 521, 544, 555, 562, 596, 600, 603, 611, 632, 642, 648, 667, 697, 709, 770, 789, 827, 852, 899, 912, 913, 965, 993};
 int b[LINENUM] = {177, -667, -222, -22, 916, 568, -9, 40, 83, -728, -345, 834, 386, -565, 735, -229, -974, 373, 951, 959, -578, 799, -280, 819, 96, -935, 285, -482, -814, 9, 306, -88, 903, -719, 365, -755, -976, 751, 472, -94, -623, 645, -677, 815, 877, 635, -439, -129, -697, -429, 695, -903, -947, -406, -56, 237, 879, 3, 183, 472, 567, -397, -577, 524, -81, 992, 671, -277, -686, 978, 268, 224, 838, 691, 729, 234, 411, 942, 356, -271, 545, 604, -488, -824, -111, 837, -110, -876, 43, -120, 856, -857, 10, 61, 720, 140, 270, 995, -796, -5};
 int v[LINENUM] = {0};
 int sub[LINENUM] = {0};

 sub[0] = 0;
 sub[1] = 1;
 curr_sub = 1;

 clock_t beg, end;

 beg = clock();

 for(i=2; i<LINENUM; i++){
     curr_sub++;
     sub[curr_sub] = i;
     k = curr_sub;
     for(ii=1; ii<curr_sub; ii++){
         for(j=0;j<ii;j++){
             if(m[sub[j]]*(b[sub[j]]-b[sub[k]])+b[sub[j]]*(m[sub[k]]-m[sub[j]])>m[sub[ii]]*(b[sub[j]]-b[sub[k]])+b[sub[ii]]*(m[sub[k]]-m[sub[j]])){
                 //line is not visible
                 sub[ii] = i;
                 curr_sub = ii;
                 break;
             }
        }
        if(sub[ii] == i){
            break;
        }
     }
 }

 //update Visibility array
 for(i=0; i<=curr_sub; i++){
     v[sub[i]]=1;
 }

 end = clock();

 printf("Visible Lines:");
 for(i=0;i<LINENUM;i++){
     printf(" %d,", v[i]);
 }
printf("\n");
printf("This algorithm took %f seconds,\n", (double)(end-beg)/CLOCKS_PER_SEC);
return(0);
}
