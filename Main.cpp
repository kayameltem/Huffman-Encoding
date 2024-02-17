#include "FileIO.h"
int main(int argc, char **argv) {

    if(argc == 4) {
            FileIO(argv[2], argv[3]);
        }
    else if (argc == 3) {
        FileIO(argv[1], argv[2]);
    }
    else if (argc == 2){
        FileIO("-l");
    }
    return 0;
}