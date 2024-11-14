//
// Created by id-ma on 14/11/2024.
//
#include "loc.h"
#include "map.h"
#include "moves.h"
#include <stdio.h>
#include <stdlib.h>
#include "time.h"

const int MAXNBCHILD = 5;
const int NUM_MOVES = 5;
const int  PHASE_MOVES = 9;

const int weight[]  = {22, 37, 44, 51, 72, 93, 100};

//Nodes of my tree
typedef struct Node {
    int cost;
    t_position position;
    t_soil soil;
    t_move move;
    t_orientation orientation;
    struct Node * parent;
    struct Node **children;
    int num_children;
    int isValidNode;
} Node;

// Function to create a tree node
Node* createNode(int cost, t_position position, t_orientation orientation, t_move move, int max_children) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->cost = cost;
    node->position = position;
    node->orientation = orientation;
    node->move = move;
    node->children = malloc(max_children * sizeof(Node *));
    node->num_children = 0;
    return node;
}


t_move * phaseMovesSelection(){
    srand(time(NULL));
    t_move * moves = malloc(PHASE_MOVES*sizeof (t_move));

    for (int i = 0; i < PHASE_MOVES; i++){
        int rand_num = rand()%100;

        if (rand_num <= weight[0]){
            moves[i] = F_10;
        }
        else if(rand_num > weight[0] && rand_num <= weight[1]){
            moves[i] = F_20;
        }
        else if(rand_num > weight[1] && rand_num <= weight[2]){
            moves[i] = F_30;
        }
        else if(rand_num > weight[2] && rand_num <= weight[3]){
            moves[i] = B_10;
        }
        else if(rand_num > weight[3] && rand_num <= weight[4]){
            moves[i] = T_LEFT;
        }
        else if(rand_num > weight[4] && rand_num <= weight[5]){
            moves[i] = T_RIGHT;
        }
        else if(rand_num > weight[5] && rand_num <= weight[6]){
            moves[i] = U_TURN;
        }
    }
    return moves;
}
