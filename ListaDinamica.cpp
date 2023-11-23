#include <iostream>

using namespace std;

// Definição da estrutura do nó da lista
struct Node {
    int data;
    Node* next;
};

// Função para inserir um elemento no final da lista
void inserirNoFim(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Função para inserir um elemento no início da lista
void inserirNoInicio(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Função para retirar um elemento do final da lista
void retirarDoFim(Node*& head) {
    if (!head) {
        cout << "Lista vazia. Impossivel retirar do fim.\n";
        return;
    }

    if (!head->next) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    Node* prev = NULL;
    while (temp->next) {
        prev = temp;
        temp = temp->next;
    }

    delete temp;
    prev->next = NULL;
}

// Função para retirar um elemento do início da lista
void retirarDoInicio(Node*& head) {
    if (!head) {
        cout << "Lista vazia. Impossivel retirar do inicio.\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

// Função para retirar um elemento do final da lista
void retirar(Node*& head, int value) {
    if (!head) {
        cout << "Lista vazia. Impossivel retirar.\n";
        return;
    }

    if (head->data == value) {
        retirarDoInicio(head);
        return;
    }

    Node* temp = head;
    Node* prev = NULL;
    while (temp && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        cout << "Elemento nao encontrado na lista.\n";
        return;
    }

    prev->next = temp->next;
    delete temp;
}

// Função para imprimir os elementos da lista
void imprimirLista(Node* head) {
    Node* temp = head;
    while (temp) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}

// Função principal
int main() {
    Node* lista = NULL;
    int escolha, valor;

    do {
        cout<<"Menu:\n";
        cout<<"1. Inserir\n";
        cout<<"2. Inserir no inicio\n";
        cout<<"3. Inserir no fim\n";
        cout<<"4. Retirar\n";
        cout<<"5. Retirar do inicio\n";
        cout<<"6. Retirar do fim\n";
        cout<<"0. Sair\n";
        cout<<"Escolha: ";
        cin >> escolha;

        switch (escolha) {
            case 1:
                cout<<"Digite o valor a ser inserido: ";
                cin>>valor;
                inserirNoFim(lista, valor);
                break;
            case 2:
                cout<<"Digite o valor a ser inserido no inicio: ";
                cin>>valor;
                inserirNoInicio(lista, valor);
                break;
            case 3:
                cout<<"Digite o valor a ser inserido no fim: ";
                cin>>valor;
                inserirNoFim(lista, valor);
                break;
            case 4:
                cout<<"Digite o valor a ser retirado: ";
                cin>>valor;
                retirar(lista, valor);
                break;
            case 5:
                retirarDoInicio(lista);
                break;
            case 6:
                retirarDoFim(lista);
                break;
            case 0:
                cout<<"Saindo do programa.\n";
                break;
            default:
                cout<<"Opcao invalida. Tente novamente.\n";
        }

        cout<<"Lista atual: ";
        imprimirLista(lista);
        cout<<"\n";

    } while (escolha != 0);

    // Libera a memória alocada para os nós da lista
    while (lista) {
        Node* temp = lista;
        lista = lista->next;
        delete temp;
    }

    return 0;
}

