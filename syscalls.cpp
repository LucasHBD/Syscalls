#include <fcntl.h>
#include <iostream>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <ctime>
#include <sys/sysinfo.h>
#include <dirent.h>
#include <cstdlib>
#include <fstream>
#include <sys/types.h>

using namespace std;


long long uptime(){
    struct sysinfo si;
    if(sysinfo(&si) != 0){
        cerr << "Erro ao chamar sysinfo" << endl;
        return -1;
    }

    return si.uptime;
}

int copy(int argc, char **argv){
    const char *sourcefn = argv[1];
    const char *targetfn = argv[2];
    int source = open(sourcefn, O_RDONLY);
    int target = open(targetfn, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    char buf[1024];
    int s;
    while((s = read(source, buf, 1024)) != 0){write(target, buf, s);}
    close(target);
    close(source);
    return 0;
}

int date(){
    time_t currentTime;
    time(&currentTime);
    cout << "Tempo atual em segundos desde a Epoch: " << currentTime << endl;
    struct tm *localTime = localtime(&currentTime);
    if(localTime != nullptr){
        cout << "Data e hora atual: " << asctime(localTime);
    } else{
        cerr << "Falha ao obter a data e hora atual." << endl;
        return 1;
    }
    return 0;
}

int ls(){
    DIR *dir;
    struct dirent *ent;

    if((dir = opendir(".")) != NULL){
        while((ent = readdir(dir)) != NULL){
            cout << ent ->d_name << endl;
        }
        closedir(dir);
    }
    else{
        cerr << "Erro ao abrir diretorio" << endl;
        return 1
    }
    return 0;
}

int rm(int argc, char *argv[]){
    if(argc != 2){
        cerr << "Uso: " << argv[0] << " <nome_do_arquivo>" << endl;
        return 1;
    }
    const char *filename = argv[1];
    if(remove(filename) == 0){
        cout << "Arquivo ' " << filename << " ' removido com sucesso." << endl;
        return 0;
    }
    else{
        cerr << "Erro ao remover arquivo" << endl;
        return 1;
    }
}

int mv(int argc, char *argv[]){
    if(argc != 3){
        cerr << "Uso: " << argv[0] << " <origem> <destino>" << endl;
        return 1;
    }
    const char *origem = argv[1];
    const char *destino = argv[2];

    if(rename(origem, destino) != 0){
        cerr << "Erro ao mover arquivo" << endl;
        return 1;
    }
    else{
        cout << "Arquivo movido com sucesso de " << origem << " para " << destino << endl;
        return 0;
    }
}

int cat(int argc, char *argv[]){
    if(argc < 2){
        cerr << "Uso: " << argv[0] << " <arquivo1 [<arquivo2> ...]" << endl;
        return 1;
    }
    for(int i = 1; i<argc; i++){
        ifstream file(argv[i]);
        if(!file.is_open()){
            cerr << "Erro ao abrir arquivo: " << argv[i] << endl;
            continue;
        }
        cout << "Conteudo do arquivo '" << argv[i] << "':" << endl;
        char c;
        while(file.get(c)){
            cout << c;
        }
        file.close();
    }
    return 0;
}

int mkdir(int argc, char* argv[]){
    if(argc != 2){
        cerr << "Uso: " << argv[0] << " <nome_do_arquivo>" << endl;
        return 1;
    }
    const char *nomeDoDiretorio = argv[1];

    if(mkdir(nomeDoDiretorio, 0777) == 0){
        cout << "Diretorio '" << nomeDoDiretorio << "' criado com sucesso." << endl;
        return 0;
    }
    else{
        cerr << "Erro ao criar diretorio" << endl;
        return 1;
    }
}

int rmdir(int argc, char *argv[]){
    if(argc != 2){
        cerr << "Uso: " << argv[0] << " <nome_do_diretorio>" << endl;
        return 1;
    }

    const char *nomeDoDiretorio = argv[1];

    if(rmdir(nomeDoDiretorio) == 0){
        cout << "Diretorio '" << nomeDoDiretorio << "' removido com sucesso." << endl;
    }
    else{
        cerr << "Erro ao remover diretorio" << endl;
        return 1;
    }
}

int chmod(int argc, char *argv[]){
    if(argc != 3){
        cerr << "Uso: " << argv[0] << " <modo_de_permissao> <nome_do_arquivo>" << endl;
        return 0;
    }

    const char *modoPermissao = argv[1];
    const char *nomeDoArquivo = argv[2];

    int modo = strtol(modoPermissao, nullptr, 8);

    if(chmod(nomeDoArquivo, modo) == 0){
        cout << "Permissoes do arquivo '" << nomeDoArquivo << "' alteradas com sucesso." << endl;
        return 0;
    }
    else {
        cerr << "Erro ao alterar as permissões do arquivo" << endl;
        return 1;
    }
}

int chown(int argc, char *argv[]){
    if(argc != 4){
        cerr << "Uso: " << argv[0] << " <usuario> <grupo> <nome_do_arquivo>" << endl;
        return 1;
    }
    const char *usuario = argv[1];
    const char *grupo = argv[2];
    const char *nomeDoArquivo = argv[3];

    uid_t uid = getpwnam(usuario) ? getpwnam(usuario)->pw_uid : -1;
    gid_t gid = getgrnam(grupo) ? getgrnam(grupo)->gr_grid : -1;

    if(uid == -1 || gid == -1){
        cerr << "Usuario ou grupo não encontrado" << endl;
        return 1;
    }
    if(chown(nomeDoArquivo, uid, gid) == 0){
        cout << "Proprietario e grupo do arquivo '" << nomeDoArquivo << "' alterados com sucesso" << endl;
        return 0;
    }
    else{
        cerr << "Erro ao alterar o proprietario e o grupo do arquivo" << endl;
        return 1;
    }
}

int main(){
    long long uptimeSec = uptime();
    if(uptimeSec >= 0){
        long long uptimeMin = uptimeSec / 60;
        long long uptimeHor = uptimeSec / 3600;
        cout << "Tempo de atividade do Sistema: " << uptimeHor << " horas" << " e " << uptimeMin << " minutos" << endl;
    } else {
        cerr << "Erro ao obter o tempo de atividade do Sistema." << endl;
    }
    return 0;
}
