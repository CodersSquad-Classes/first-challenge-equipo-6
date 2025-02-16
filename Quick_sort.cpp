#include <iostream>
#include <vector>

template<typename T>
int partition(std::vector <T>& lista, int low, int high){  
    int pivote = lista[high];
    int i = low - 1;

    for(int j = low; j <= high - 1; j++){
        if(lista[j] < pivote){
            i++;
            std::swap(lista[i],lista[j]);
        }
    }
    
    std::swap(lista[i+1],lista[high]);
    return i + 1;

}
  
template<typename T>
void quick_sort(std::vector <T>& lista, int low, int high){
    if(low < high){
        int pi = partition(lista, low, high);

        quick_sort(lista, low, pi - 1);
        quick_sort(lista, pi + 1, high);
    }
}
