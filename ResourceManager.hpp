#pragma once

#include "Resource.hpp"

class ResourceManager
{
    private: 
        Resource *ok; 
    public: 
        ResourceManager()  {
            ok = new Resource();
             } // konstruktor domyœlny 
		
        
        double get()  //metoda double get
        {
        	return ok->get();
		}
        
        ResourceManager(const ResourceManager& i)  // konstruktor kopiuj¹cy
        {
        	ok = new Resource();
        	*ok = *(i.ok);	//kopiujê wartoœæ
		}
        
    	ResourceManager& operator=(const ResourceManager& i)  //kopiuj¹cy operator przypisania
    	{
    		*ok = *i.ok;
    		return *this;  //gdy korzystamy z operatora przypisania korzystamy z return 
		}
		
		ResourceManager(ResourceManager&& i)  //konstruktor przenosz¹cy
		{
			ok = (i.ok);
			i.ok = nullptr;  //nullptr to wskaŸnik pusty
		}
		
		ResourceManager& operator=(ResourceManager&& i)  //przenosz¹cy operator przypisania
    	{
    		delete ok;
    		ok = i.ok;
    		i.ok = nullptr;
    		return *this;
		}
		
		~ResourceManager()
		{
			delete ok;
		}
		
};