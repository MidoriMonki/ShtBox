#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;
class Entity;

using ComponentID = std::size_t;

inline ComponentID getComponentTypeID() noexcept{
    static ComponentID lastID = 0;
    return lastID++;
}

template <typename T> inline ComponentID getComponentTypeID() noexcept{
    static ComponentID typeID{ getComponentTypeID() };
    //static ComponentID typeID = getComponentTypeID();
    return typeID;
}

constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;

class Component{
    public:
        Entity* entity;
        virtual void init() {}
        virtual void update() {}
        virtual void draw() {}
        virtual ~Component() {}
};

class Entity{
    private:
        bool active = true;
        std::vector<std::unique_ptr<Component>> components;

        ComponentArray componentArray;
        ComponentBitSet componentBitSet;

    public:
        int number = 3;
        void update(){
            for(auto& c : components) c->update();
        }
        void draw(){
            for(auto& c : components) c->draw();
        }
        bool isActive() const{
            return active;
        }
        void destroy(){
            active = false;
        }

        template <typename T> bool hasComponent() const{
            return componentBitSet[getComponentTypeID<T>];
        }

        template <typename T, typename... TArgs>
        T& addComponent(TArgs&&... mArgs){
            T* c(new T(std::forward<TArgs>(mArgs)...));
            c->entity = this;
            components.emplace_back(std::move(/*uPtr*/c));

            componentArray[getComponentTypeID<T>()] = c;
            componentBitSet[getComponentTypeID<T>()] = true;

            c->init();
            return *c;
        } 

        template <typename T> T& getComponent() const{
            auto ptr(componentArray[getComponentTypeID<T>()]);
            return *static_cast<T*>(ptr);
        }

        //gameObject.getComponent<PositionComponent>().setXpos(25);

};

class Manager{
    private:
        std::vector<std::unique_ptr<Entity>> entities;

    public:
        void update(){
            for(auto& e : entities) e->update();
        }
        void draw(){            
            //entities[0].getComponent<SpriteComponent>().draw();
            //entities[0]->components[1]->draw;
            for(auto& e : entities) e->draw();
        }
        void refresh(){
            entities.erase(std::remove_if(std::begin(entities), std::end(entities), 
                [](const std::unique_ptr<Entity> &mEntity){
                    return !mEntity->isActive();
                }),
                std::end(entities));
        }

        Entity& addEntity(){
            std::cout<<"meow"<<std::endl;
            Entity* e = new Entity();
            std::unique_ptr<Entity> uPtr{ e };
            entities.emplace_back(std::move(uPtr));
            return *e;
        }
};

