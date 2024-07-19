#ifndef GRAFOL_HPP
#define GRAFOL_HPP

#include <cstddef>
#include "ParOrdenado.hpp"

#define INF 999.0

class Vertex;

struct Aresta{
    Vertex* verticeConectado;
    float tamanhoAresta;
    bool portal;
    Aresta* next;

    Aresta(Vertex* v, float distancia, bool portal): verticeConectado(v), tamanhoAresta(distancia),
    portal(portal), next(nullptr) {};
    ~Aresta() = default;
};

class Vertex{

    private:
        int id;
        ParOrdenado cord;
        Vertex* next;
        Aresta* arestaHead;
        Aresta* arestaTail;
    public:
        Vertex(int id, int x, int y);
        ~Vertex();

        void addAresta(Vertex* v, bool isPortal);
        Aresta* getArestas() const;
    
    friend class GrafoList;
};

class GrafoList{
    private:
        int maxVertices;
        int maxArestas;
        Vertex* verticesHead;
        Vertex* verticesTail;
        int verticesAdicionados;

        Vertex* findVertice(int id);

    public:
        GrafoList(int maxVertices, int maxArestas);
        ~GrafoList();

        void addVertice(int id, int x, int y);
        void addAresta(int id1, int id2, bool isPortal = false);


        float getPesoAresta();
        
        int djkistra(int energia, int maxPortais);
};

#endif