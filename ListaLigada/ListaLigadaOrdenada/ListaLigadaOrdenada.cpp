#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	if (posicaoElemento(novo->valor) != NULL) {
		cout << "O numero ja esta na lista" << endl;
		return;
	}

	if (primeiro == NULL)
	{
		primeiro = novo;
	}
	else
	{
		// procura o final da lista
		NO* aux = primeiro;
		while (aux->prox != NULL) {
			aux = aux->prox;
		}
		aux->prox = novo;
	}


	NO* aux = primeiro;
	while (aux->prox != NULL) {
		if (aux->valor > novo->valor) {
			int substituir = novo->valor;
			novo->valor = aux->valor;
			aux->valor = substituir;
		}
		aux = aux->prox;
	}
}

void excluirElemento()
{
	int valor;
	cout << "Digite o elemento que queira excluir:" << endl;
	cin >> valor;
	NO* buscar = posicaoElemento(valor);

	if (buscar != NULL) {
		NO* aux = primeiro;
		NO* excluir = NULL;

		if (aux->valor == valor) {
			excluir = primeiro;
			primeiro = aux->prox;
			free(excluir);
		}
		else if (aux->prox != NULL) {
			while (aux->prox->valor == valor) {
				excluir = aux->prox;
				free(excluir);
				break;
			}
		}
	}
	else {
		cout << "Elemento nao encontrado" << endl;
	}
}

void buscarElemento()
{
	int numero;
	cout << "Digite o elemento que queira buscar:" << endl;
	cin >> numero;
	NO* buscar = posicaoElemento(numero);
	NO* aux = primeiro;

	if (buscar != NULL) {
		while (aux->prox->valor < numero) {
			aux = aux->prox;
		}
		NO* posicao = aux->prox;
		cout << "Elemento encontrado na posicao " << posicao << endl;
	}
	else {
		cout << "Elemento nao encontrado" << endl;
	}
}


NO* posicaoElemento(int numero)
{
	NO* aux = primeiro;
	while (aux != NULL) {
		if (aux->valor == numero)
		{
			break;
		}
		aux = aux->prox;
	}
	return aux;
}




