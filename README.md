# Trabalho Sobre Chamadas de Sistemas

| COMANDO             | DESCRIÇÃO           |
| :-----------------: | :-----------------: |
| date | utilizando a função "time()" é possivel conseguir o tempo em segundos desde a Epoch (1 de Janeiro de 1970, 00:00:00 UTC |
| uptime | utiliza-se a função "getUpTime()" para acessar a função "sysinfo()" que da acesso as informações do sistema incluindo o tempo de boot |
| ls | utiliza-se as funções "opendir()" e "closedir()" para abrir e fechar diretórios a fim de listá-los |
| cp | abre-se o arquivo desejado em função de leitura apenas "O_RDONLY", cria-se um arquivo de destino caso ele n tenha sido criado, copia o conteudo do arquivo fonte, depois armazena os dados lidos no arquivo de destino |
| rm | utiliza-se a função "remove()" para deletar um arquivo |
| mv | usa-se a função "rename()" para tentar mover o arquivo de origem para o destino especificado. Se a operação for bem-sucedida, uma mensagem de sucesso é exibida; caso contrário, uma mensagem de erro é exibida usando "cerr" |
| cat | abre-se cada arquivo fornecido em um loop, lê-se seu conteúdo caractere por caractere e o imprime na saída padrão "stdout". Se houver um erro ao abrir um arquivo, uma mensagem de erro é exibida |
| mkdir | utiliza-se 2 parametros para utilização da funçao "mkdir()", o nome do diretorio desejado e a permissão 0777, que permite que o diretório seja lido, escrito e executado em todos os usuários |
| rmdir | remove um diretório utilizando a função "rmdir()" |
| chmod | converte-se o modo de permissão fornecido pelo usuário para um número octal usando a função "strtol()", Usa-se a função "chmod()" para alterar as permissões do arquivo com o nome especificado, o segundo argumento é o modo de permissão no formato octal |
| chown | Usa-se as funções getpwnam() e getgrnam() para obter o identificador numérico (UID e GID) do usuário e do grupo especificados, Usa-se a função "chown()" para alterar o proprietário e o grupo do arquivo com o nome especificado. Os dois últimos argumentos são o UID e o GID |
