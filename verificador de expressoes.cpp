#include <iostream>
#include <stack>
#include <string>

using namespace std;

// verificar se o carctere é um delimitador de abertura -> (, [, {
bool isOpenDelimiter(char c) {
    return c == '(' || c == '[' || c == '{'; 
}

// verificar se o caractere é um delimitador de fechamento -> ), ], }
bool isCloseDelimiter(char c){
    return c == ')' || c == ']' || c == '}';
}

// verifica se os dois delimitadores formam um par valido
bool isMatchingPair(char open, char close){
    return (open == '(' && close == ')') ||
            (open == '[' && close == ']') ||
            (open == '{' && close == '}');
}

// função que verifica se a expressão está balanceado
// retorna true se sim ou false se não
bool isBalanced (const string& expressao){
    stack<char> s;

    for(size_t i = 0; i < expressao.length(); i++){
        char c = expressao[i];

        // se esse char for de abertura, empilha
        if(isOpenDelimiter(c)) {
            s.push(c);
        }

        // se esse char for de fechamento, verifico se há correspondência
        else if (isCloseDelimiter(c)){
            // se a pilha estive vazia, não há possibilidade de abertura correspondente
            if (s.empty()){
                return false;
            }

            // verifico se o topo da pilha corresponde ao fechamento
            char top = s.top();
            if(!isMatchingPair(top, c)){
                return false;
            }

            // remove o delimitador de abertura correspondente
            s.pop();
        }
    }
    // a expressao está balanceada se no final da verificação de todos os elementos do for a pilha estiver vazia
    return s.empty();
}

// função adicional para exibir o resultado de forma legivel, + facil
void testExpression(const string& expr) {
    cout << "Expressão: " << expr << " -> ";
    if(isBalanced(expr)){
        cout << " BALANCEADA! " << endl;
    } else {
        cout << " NÃO BALANCEADA " << endl;
    }
}

int main(){
    cout << " === VERIFICADOR DE BALANCEAMENTO === " << endl << endl;

    // casos de teste
    testExpression("{[()()]}");
    testExpression("{[(])}");
    testExpression("((a+b)*[c-d])"); 
    testExpression("((a+b)"); 
    testExpression("{{{{}}}}");
s
    cout << endl << "Versão interativa" << endl;
    cout << "Digite uma expressão ou sair para encerrar: ";

    string input;
    getline(cin, input);

    while(input != "sair" || input != "SAIR") {
        testExpression(input);
        cout << endl << "Digite outra expressao ou sair: ";
        getline(cin, input);
    }

    return 0;
}