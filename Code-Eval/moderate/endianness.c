int main() {
    int test = 0xff00;
    unsigned char* bytePtr = &test;
    
    if( (*bytePtr) == 0xf && (*bytePtr)++ == 0xf) {
        printf("BigEndian");
    }
    else {
        printf("LittleEndian");
    }
}