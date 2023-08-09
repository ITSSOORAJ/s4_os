#include<stdio.h>
#include<unistd.h>
void main()
{
printf("hello i am the main process \n");
printf("process id is pid=%d \n",getpid());
char*args[]={"./hello",NULL};
execv(args[0],args);
printf("BLA BLA BLA");
}
