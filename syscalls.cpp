#include <fcntl.h>
#include <unistd.h>
#include <windows.h>
#include <iostream>

using namespace std;

int cp(int argc, char **argv){
    const char *sourcefn = argv[1];
    const char *targetfn = argv[2];
    int source = CreateFile(sourcefn, O_RDONLY);
    int target = CreateFile(targetfn, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    char buf[1024];
    int s;
    while((s = read(source, buf, 1024)) != 0)
        write(target, buf, s);
    close(target);
    close(source);
    return 0;
}

int date(){
    SYSTEMTIME sysTime;
    GetSystemTime(&sysTime);
    cout << "Dia: " << sysTime.wDay << endl;
    cout << "Mês: " << sysTime.wMonth << endl;
    cout << "Ano: " << sysTime.wYear << endl;
    cout << "Horas: " << sysTime.wHour << endl;
    cout << "Minutos: " << sysTime.wMinute << endl;
    cout << "Segundos: " << sysTime.wSecond << endl;
    cout << "Milisegundos: " << sysTime.wMilliseconds << endl;
    return 0;
}

int main(){

    return 0;
}