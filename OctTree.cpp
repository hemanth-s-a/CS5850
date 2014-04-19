#include "OctTree.h"



OctTree::OctTree(BoundingBox *bound,int level){
    this->bound = bound;
    this->level = level;
    this->objects = new vector<Shape*>();
   // printf("%d %f %f %f %f %f %f \n", level, bound->min.x,bound->min.y,bound->min.z,bound->max.x,bound->max.y,bound->max.z);

    if(level < MAX_LEVELS){
        int hlength = (bound->max.x - bound->min.x)/2;
        int hwidth = (bound->max.x - bound->min.x)/2;
        int hheight = (bound->max.x - bound->min.x)/2;

        BoundingBox *b1 = new BoundingBox(bound->min.x,bound->min.y,bound->min.z,
                                         bound->min.x + hlength,bound->min.y +hwidth,bound->min.z + hheight);
        BoundingBox *b2 = new BoundingBox(bound->min.x+hlength,bound->min.y,bound->min.z,
                                         bound->max.x,bound->min.y +hwidth,bound->min.z + hheight);
        BoundingBox *b3 = new BoundingBox(bound->min.x,bound->min.y+hwidth,bound->min.z,
                                         bound->min.x + hlength,bound->max.y,bound->min.z + hheight);
        BoundingBox *b4 = new BoundingBox(bound->min.x + hlength,bound->min.y+hwidth,bound->min.z,
                                         bound->max.x ,bound->max.y,bound->min.z + hheight);

        BoundingBox *b5 = new BoundingBox(bound->min.x,bound->min.y,bound->min.z + hheight,
                                         bound->min.x + hlength,bound->min.y +hwidth,bound->max.z);
        BoundingBox *b6 = new BoundingBox(bound->min.x+hlength,bound->min.y,bound->min.z + hheight,
                                         bound->max.x,bound->min.y +hwidth,bound->max.z);
        BoundingBox *b7 = new BoundingBox(bound->min.x,bound->min.y+hwidth,bound->min.z + hheight,
                                         bound->min.x + hlength,bound->max.y,bound->max.z);
        BoundingBox *b8 = new BoundingBox(bound->min.x + hlength,bound->min.y+hwidth,bound->min.z + hheight,
                                         bound->max.x ,bound->max.y,bound->max.z);

        this->child = new vector<OctTree*>();

        this->child->push_back(new OctTree(b1,level+1));
        this->child->push_back(new OctTree(b2,level+1));
        this->child->push_back(new OctTree(b3,level+1));
        this->child->push_back(new OctTree(b4,level+1));
        this->child->push_back(new OctTree(b5,level+1));
        this->child->push_back(new OctTree(b6,level+1));
        this->child->push_back(new OctTree(b7,level+1));
        this->child->push_back(new OctTree(b8,level+1));
    }else{
        this->child = NULL;
    }

}


void OctTree::insert_object(Shape *p){
    BoundingBox *obj_box = p->getBoundingBox();
    if(bound->contains(obj_box))
    {
        bool is_inserted = false;
        if(child != NULL)
        {
            for(size_t i=0; i < child->size() ; i++ )
            {
                if(child->at(i)->bound->contains(obj_box))
                {
                    child->at(i)->insert_object(p);
                    is_inserted = true;
                }
            }
        }
        if(!is_inserted){
            printf("%d %f %f %f %f %f %f \n", level, bound->min.x,bound->min.y,bound->min.z,bound->max.x,bound->max.y,bound->max.z);
            objects->push_back(p);
        }

    }else{
        printf("not insert %d \n",level);
    }

}

void OctTree::get_colliding_objects_bb(vector< vector<Shape*>* >* colliding_objects){

    vector<Shape*> * parent_objects = new vector<Shape*>();
    get_colliding_objects_bb(colliding_objects,parent_objects);
    delete parent_objects;

}

void OctTree::get_colliding_objects_bb(vector< vector<Shape*>* >* colliding_objects,vector<Shape*> * parent_objects){

    colliding_objects_in_node(colliding_objects);
    colliding_objects_parent(colliding_objects,parent_objects);

    int size_parent_list = parent_objects->size();
    parent_objects->insert(parent_objects->end(),objects->begin(),objects->end());
    if(child != NULL){
    for(size_t i=0; i< child->size() ; i++){
        child->at(i)->get_colliding_objects_bb(colliding_objects,parent_objects);
    }
    }
    parent_objects->erase(parent_objects->begin()+size_parent_list, parent_objects->end());

}

void OctTree::colliding_objects_in_node(vector< vector<Shape*>* >* colliding_objects)
{
    for(size_t i=0; i< objects->size() ; i++)
    {
        for(size_t j=i; j < objects->size() ; j++)
        {
            if(i==j)
                continue;

            if(objects->at(i)->getBoundingBox()->collide(objects->at(j)->getBoundingBox()))
            {
                vector<Shape*> *colliding_pair = new  vector<Shape*>();
                colliding_pair->push_back(objects->at(i));
                colliding_pair->push_back(objects->at(j));
                colliding_objects->push_back(colliding_pair);
            }
        }
    }

}


void OctTree::colliding_objects_parent(vector< vector<Shape*>* >* colliding_objects,vector<Shape*> * parent_objects)
{
    for(size_t i=0; i< parent_objects->size() ; i++)
    {
        for(size_t j=0; j < objects->size() ; j++)
        {
            if(parent_objects->at(i)->getBoundingBox()->collide(objects->at(j)->getBoundingBox()))
            {
                vector<Shape*> *colliding_pair = new  vector<Shape*>();
                colliding_pair->push_back(parent_objects->at(i));
                colliding_pair->push_back(objects->at(j));
                colliding_objects->push_back(colliding_pair);

            }
        }
    }

}

