Бинарное дерево поиска
Binry search tree - BST
Граф - это множество пар вида (V, E) V - вершина, E - ребра
Деревно - это ацикличный граф
Корневное дерево - дерево с выделенной одной вершиной называемой корнем
Узел - это вершина в коневом дереве
Предок - это узел лежащий на пути от корня дерева к рассматриваемой вершине и отстоящий от него на длину ребра (единственный или кратчайший путь)
Поддерево с корнем в узле y - это дерево порожденное узлом y и всеми его потомками
Количество потомков того или иного узла называется степенью этого узла
Простой путь - это путь при котором ребро проходится один раз
Глубина узла - это длина простого пути, измеряемая в ребрах
Высота узла - количество вершин в простом пути от листа до узла, при этом берется самый длинный путь

Корень - узел у которого нет предков
Лист - узел у которого нет потомков

Бинарное дерево - это конечное множество узлов, которое является корневым, либо является корнем левого или правого поддерева (может не содержать узлов)
BST - это бинарное деревно в котором значение узлов в левом поддереве меньше чем значнеие корня этого поддерева, 
а значения в правом поддереве больше значения в корне (одинаковые значения не рассматриваются)

struct Node {
    int value;
    Node left, right, parent;
};

struct BST {
    Node root;
};

Как вывести дерево?
Существует несколько порядков в которых можно обходить дерево

1) Симметричный - выдавет спроецированное бинарное дерево, соответственно оно будет отсортированно в порядке возрастания 
    Order Walk(x)
        in x != nullptr
            Order(x -> left)
            print (x)
            Order(x -> right)

2) Прямой 
    Preorder Walk(x)
        in x != nullptr
            Order(x -> left)
            Order(x -> right)
            print (x)

3) Обратный 
    Postorder Walk(x)
        in x != nullptr
            print (x)
            Order(x -> left)
            Order(x -> right)

Поиск значения элемента в дереве
find (Node n, int value)
    if x == nullptr || x->kay == value {
        return x;
    }        
    if value < x->kay {
        return find(x->left, value);
    }
    else return find(x->right, value);

Вставка нового элемента в дерево
    Node* x = new Node (value, nullptr, nullptr, nullptr);
    Incert (T, Node* x) {
        curr = root
        while (curr != nullptr) {
            if x->kay < curr(left)
                curr = curr->left
            else
                curr = curr->right
        }
    }

Порча дерева удалением элемента
    1 случай - удаление листа
    2 случай - удаение "полулиста"
    3 случай - проблемный, когда есть два потомка
        а - у правого нет левого потомка
        б - у всех есть потомки

Перенос дерева
Стриание поддерева

Сбаласированные деревья
Поворот
АВЛ дерево 