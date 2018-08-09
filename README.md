# ft_irc

42 project which aims to create a IRC-like server and client.

## Supported commands

/nick <nickname>  
/join <#channel>  
/leave [#channel]  
/who  
/msg <nick/#channel> <message>  
/connect <machine> [port]

## Compiling

Make sure you have the libft library by running `git submodule init && git submodule update`.  
You may compile the executables `client` and `serveur` by running `make`.

## Usage

Start the server with `./serveur <port>`.  
Then join it with `./client <machine> <port>`.
