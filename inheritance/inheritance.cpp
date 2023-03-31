#include <iostream>
#include <stdexcept>
#include <vector>


enum AnimalType      {CAT, PARROT};
enum FoodType        {MEAT, FRUIT};


namespace MeetType {

	const std:: string BEEF   =   "beef";
	const std:: string MUTTON = "mutton";
}

namespace FruitType {

	const std:: string APPLE  =  "apple";
	const std:: string ORANGE = "orange";
}


class Food {

	private:
		double calories;
		FoodType   type;

	public:
		Food(double m_calories, FoodType m_type);
		FoodType GetType() {return type; }
		double GetCalories() {return calories; }
};


class Meat : public Food {

	private:
		std:: string nameMeat;

	public:
		Meat(double m_calories = 0, std:: string m_nameMeat = "None") :
		Food(m_calories, MEAT), nameMeat(m_nameMeat) {}
};


class Fruit : public Food {

	private:
		std:: string nameFruit;

	public:
		Fruit(double m_calories = 0, std:: string m_nameFruit = "None") :
		Food(m_calories, FRUIT), nameFruit(m_nameFruit) {}
};


class Animal {

	protected:
		std:: string       name;
		int                 age;
		double          satiety;
		double      MaxFoodSize;
		AnimalType         type;

	public:
		Animal(std:: string m_name = "None", int m_age = 0,
			   AnimalType m_AnimalType = CAT, double m_satiety = 0,
			   double m_MaxFoodSize = 0);

		template<class T, class T1>
		void Eat(T1 & food, std:: vector<T> & vect);

		AnimalType GetAnimalType() {return type; }

		template<class T>
		void Multiply(Animal & animal, std:: vector<T> & vect);

		template<class T>
		void Run(size_t minutes, std:: vector<T> & vect);
};


class Cat : public Animal {

	private:
		double         LengthTeeth;
		std:: string FavouriteMeat;

	public:
		Cat(std:: string m_name = "None", int m_age = 0,
		    double m_satiety = 0, double m_MaxFoodSize = 0, 
		    double m_LengthTeeth = 0, std:: string m_FavouriteMeat = "None") :
			Animal(m_name, m_age, CAT, m_satiety, m_MaxFoodSize), 
			LengthTeeth(m_LengthTeeth), FavouriteMeat(m_FavouriteMeat) {}

		Cat(Animal & copy, double m_LengthTeeth = 0, 
			std:: string m_FavouriteMeat = 0) : Animal(copy), 
		LengthTeeth(m_LengthTeeth), FavouriteMeat(m_FavouriteMeat) {}
		void Show();
};


class Parrot : public Animal {

	public:
		Parrot(std:: string m_name = "None", int m_age = 0,
			   double m_satiety = 0, double m_MaxFoodSize = 0) :
			   Animal(m_name, m_age, PARROT, m_satiety, m_MaxFoodSize) {}

		Parrot(Animal & copy) : Animal(copy) {}
};


template <class T>
void Remove(std:: vector<T> & vect, size_t index);


int main() {

	std:: vector<Cat> cat(5);
	cat[0] = Cat("name1",  11,  53,  100, 41,   "beef");
	cat[1] = Cat("name2",   8,  47,  100, 14, "mutton");
	cat[2] = Cat("name3",  13,  22,   75, 28,   "beef");
	cat[3] = Cat("name4",   7,  11,  100, 47, "mutton");
	cat[4] = Cat("name5", 100,   0,  100, 54,   "beef");

	Meat meat(1400, "beef");
	cat[2].Eat(meat, cat);
	cat[3].Run(8000, cat);


	return 0;
}


Animal:: Animal(std:: string m_name, int m_age, AnimalType m_AnimalType, 
				double m_satiety, double m_MaxFoodSize) {

	name        =        m_name;
	age         =         m_age;
	type        =  m_AnimalType;
	satiety     =     m_satiety;
	MaxFoodSize = m_MaxFoodSize;
}


Food:: Food(double m_calories, FoodType m_type) {

	calories = m_calories;
	type     =     m_type;
}


template<class T, class T1>
void Animal:: Eat(T1 & food, std:: vector<T> & vect) {

	if(this->type == CAT && food.GetType() != MEAT)
		throw std:: invalid_argument("Cat doesn't eat not meat.");

	else if(this->type == PARROT && food.GetType() != FRUIT)
		throw std:: invalid_argument("Parrot doesn't eat not fruits.");

	if(food.GetCalories() > MaxFoodSize) {

		int index = 0;
		for(index = 0; index < vect.size(); index++) {

			if(this == &vect[index]) {

				std:: cout << "Animal №" << index + 1 << " was removed.";
				std:: cout << std:: endl; 
				Remove(vect, index);
			}
		}
	}

	satiety += food.GetCalories();
}


template<class T>
void Animal:: Multiply(Animal & animal, std:: vector<T> & vect) {

	if(this == &animal) {

		std:: cout << "Error. Auto-muptiply" << std:: endl;

		int index = 0;
		for(index = 0; index < vect.size(); index++) {

			if(&animal == &vect[index]) {

				std:: cout << "Animal №" << index + 1 << " was removed.";
				std:: cout << std:: endl; 
				Remove(vect, index);
			}
		}

		return;
	}

	else if(this->type != animal.GetAnimalType()) {

		std:: cout << "Error. It's multiplying of 2 different animals." <<
		std:: endl;
		return;
	}
}


template <class T>
void Remove(std:: vector<T> & vect, size_t index) {

    vect.erase(vect.begin() + index);
}


template<class T>
void Animal:: Run(size_t minutes, std:: vector<T> & vect) {

	satiety-= minutes;

	if(satiety < 0) {

		int index = 0;
		for(index = 0; index < vect.size(); index++) {

			if(this == &vect[index]) {

				std:: cout << "Animal №" << index + 1 << " was removed.";
				std:: cout << std:: endl; 
				Remove(vect, index);
			}
		}
	}
		
}


void Cat:: Show() {

	std:: cout << "name: "     << name        << std:: endl;
	std:: cout << "age: "      << age         << std:: endl;
	std:: cout << "satiety: "  << satiety     << std:: endl;
	std:: cout << "max food: " << MaxFoodSize << std:: endl;
	
	if(!type)
	std:: cout << "type: CAT"                 << std:: endl;
}
