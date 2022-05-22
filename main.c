#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NF 2 //node freedom = 2
#define PU 4 //node num per unit, as required

typedef struct Material {float E, v;} Material;
typedef struct Node {int x, y; int global_id; } Node;
typedef struct Unit4 {Node a, b, c, d;} Unit4;

/*-------accorrding to abaque-------------------*/
int node_num; 
int unit_num;
Node* NodeList;


/*----------------------------------------------*/
int material_num;
Material* MaterialList;

/*----------------------------------------------*/
int force_num;
/*----------------------------------------------*/
int x_constrained_node_num, y_constrained_node_num;


void print_node_inf(){
    for(int i=0; i<node_num; i++){
        printf("node%d:\nx:%d y:%d\n", i+1, NodeList[i].x, NodeList[i].y);
    }
}

void print_material_inf(){
    for(int i=0; i<material_num; i++){
        printf("material%d:\nE:%f v:%f\n", i+1, MaterialList[i].E, MaterialList[i].v);
    }
}


int main(int argc, char** argv){

    if(argc>1){
        if(strcmp(argv[1], "-i")==0){//input in cmd
            printf("please input node num:\n");
            scanf("%d", &node_num);
            NodeList=(Node*)malloc(sizeof(Node)*node_num);
            for(int i=0; i<node_num; i++){
                printf("please input %d-th node inf(cord of x,y):\n", i+1);
                scanf("%d %d",&NodeList[i].x, &NodeList[i].y);
                NodeList[i].global_id=i;
            }
            printf("\nnode coordination inf confirmed!\n\nplease input material-kind num:\n");//node coordination loaded
            scanf("%d", &material_num);
            MaterialList=(Material*)malloc(sizeof(Material)*material_num);
            for(int i=0; i<material_num; i++){
                printf("please input %d-th material inf(E, v):\n", i+1);
                scanf("%f %f",&MaterialList[i].E, &MaterialList[i].v);
            }
            printf("\nmaterial inf confirmed!\n\nplease input material-kind num:\n");//material loaded




            print_material_inf();
            print_node_inf();
        }
    }

}
