#pragma once

#include <iostream>
#include <vector>
#include <list>

//recieved help from Jo Gentry

template <typename T>
class Graph {
public:
    virtual ~Graph() {}
    virtual bool adjacent(T x, T y) = 0;
    virtual std::vector<T> neighbors(T x) = 0;
    virtual void addEdge(T source, T dest) = 0;
    virtual void addNode(T x) = 0;
    virtual void deleteEdge(T source, T dest) = 0;
    virtual void deleteNode(T node) = 0;
    virtual size_t size() const = 0;
};

template <typename T>
class AdjacencyListGraph : public Graph<T> {
private:
    std::vector<std::list<T>> adjacencyList;

public:
    AdjacencyListGraph(size_t n) : adjacencyList(n) {}

    bool adjacent(T x, T y) override {
        for (const auto& neighbor : adjacencyList[x]) {
            if (neighbor == y) {
                return true;
            }
        }
        return false;
    }

    std::vector<T> neighbors(T x) override {
        return std::vector<T>(adjacencyList[x].begin(), adjacencyList[x].end());
    }

    void addEdge(T source, T dest) override {
        adjacencyList[source].push_back(dest);
        adjacencyList[dest].push_back(source);
    }

    void addNode(T x) override {
        if (x >= adjacencyList.size()) {
            adjacencyList.resize(x + 1);
        }
    }

    void deleteEdge(T source, T dest) override {
        adjacencyList[source].remove(dest);
        adjacencyList[dest].remove(source);
    }

    void deleteNode(T node) override {
        for (auto& neighbors : adjacencyList) {
            neighbors.remove(node);
        }
        adjacencyList[node].clear();
    }
    size_t size() const override {
        return adjacencyList.size();
    }
};

template <typename T>
class AdjacencyMatrixGraph : public Graph<T> {
private:
    std::vector<std::vector<bool>> adjacencyMatrix;

public:
    AdjacencyMatrixGraph(size_t n) : adjacencyMatrix(n, std::vector<bool>(n, false)) {}

    bool adjacent(T x, T y) override {
        return adjacencyMatrix[x][y];
    }

    std::vector<T> neighbors(T x) override {
        std::vector<T> result;
        for (T i = 0; i < adjacencyMatrix.size(); ++i) {
            if (adjacencyMatrix[x][i]) {
                result.push_back(i);
            }
        }
        return result;
    }

    void addEdge(T source, T dest) override {
        adjacencyMatrix[source][dest] = true;
        adjacencyMatrix[dest][source] = true; 
    }

    void addNode(T x) override {
        if (x >= adjacencyMatrix.size()) {
            size_t n = x + 1;
            adjacencyMatrix.resize(n, std::vector<bool>(n, false));
            for (size_t i = 0; i < n; ++i) {
                adjacencyMatrix[i].resize(n, false);
            }
        }
    }

    void deleteEdge(T source, T dest) override {
        adjacencyMatrix[source][dest] = false;
        adjacencyMatrix[dest][source] = false;
    }

    void deleteNode(T node) override {
        size_t n = adjacencyMatrix.size();
        if (node < n) {
            for (size_t i = 0; i < n; ++i) {
                adjacencyMatrix[i][node] = false;
                adjacencyMatrix[node][i] = false;
            }
        }
    }
    size_t size() const override {
        return adjacencyMatrix.size();
    }
};