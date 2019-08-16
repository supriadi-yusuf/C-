/************************************************************************
print immediately any pressed key to console until q is pressed.
source : https://shtrom.ssji.net/skb/getc.html
************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <termios.h>

int get_key_pressed(void){
  struct termios old_tio, new_tio;
  unsigned char c;

  //get the terminal settings for stdin
  tcgetattr(STDIN_FILENO, &old_tio);

  //keep the old settings so we can restore them at the end
  new_tio = old_tio;

  //disable canonical mode (buffered i/o) and local echo
  new_tio.c_lflag &= (~ICANON & ~ECHO);

  //set the new settings immediately
  tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);

  c = getchar(); 

  //restore former setting
  tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);

  return c;
}

int main(int argc, char **argv){
  unsigned char c;

  printf("press q to exit ...\n");

  do{
    c = get_key_pressed();
    printf("%d\n", c);
  }while(c!='q');
  
  return 0;  
}

//compile : gcc wait4key.c -o wait4key
