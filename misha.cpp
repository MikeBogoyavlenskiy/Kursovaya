/*

Определить класс «Мифические создания».
 Базовый класс определяет интерфейс для построения различных частей мифического создания,
  но эти части могут быть специализированы для конкретного создания (размер, цвет, свойства,
   к какой мифологии относится, наименование, краткое описание итогового создания (текст), как атакует).
    Использовать паттерн «Одиночка». Результат и все характеристики записываются в выходной файл.
     Пользователь может загрузить созданий из файла.
*/


#include <iostream>
#include <string>
#include <fstream>

class Myth_Creature
{
public:

	Myth_Creature(){};
	~Myth_Creature(){};

	void set_color(std::string clr){
		this->color = clr;
	}

	void set_env(std::string  env){
		this->env = env;
	}
	
	void set_mythology(std::string  mythology){
		this->mythology = mythology;
	}

	void set_description(std::string  description){
		this->description = description;
	}

	void set_how_attack(std::string  how_attack){
		this->how_attack = how_attack;
	}

	void out_file()	{
		 std::ofstream ofs (this->name+".txt", std::ofstream::out);
		 ofs << this->get_name() <<  "\n";
		 ofs << this->get_size() <<  "\n";
		 ofs << this->get_env() <<  "\n";
		 ofs << this->get_description() <<  "\n";
		 ofs << this->get_color() <<  "\n";
		 ofs << this->get_how_attack() <<  "\n";
		 ofs << this->get_mythology() <<  "\n";
		 ofs.close();
	}

	void from_file(std::string name) {
		std::ifstream ifs (name+".txt");
		std::string str;
		ifs >> str;
		this->set_name(str);
				ifs >> str;
		this->set_size(str);
				ifs >> str;
		this->set_env(str);
				ifs >> str;
		this->set_description(str);
				ifs >> str;
		this->set_color(str);
				ifs >> str;
		this->set_how_attack(str);
				ifs >> str;
		this->set_mythology(str);
	}

	void set_size(std::string size){
		this->size = size;
	}

	void set_name(std::string name){
		this->name = name;
	}

	std::string get_name(){
		return this->name;
	}

	std::string get_size(){
		return this->size;
	}

	std::string get_color(){
		return this->color;
	}

	std::string get_env(){
		return this->env;
	}
	
	std::string get_mythology(){
		return this->mythology;
	}

	std::string get_description(){
		return this->description;
	}

	std::string get_how_attack(){
		return this->how_attack;
	}

private:
	std::string color;
	std::string size;
	std::string env;
	std::string mythology;
	std::string name;
	std::string description;
	std::string how_attack;
};


class Medooza : public Myth_Creature
{
public:
	static Medooza& Instance()
	{
		static Medooza theSingleInstance;
		return theSingleInstance;
	}

private:
	Medooza(){
		this->set_color("green");
		this->set_size("2");
		this->set_mythology("greek");
		this->set_how_attack("look");
		this->set_env("wooman");
		this->set_name("medooza");
		this->set_description("-");

	};
	Medooza(const Medooza& root) = delete;
	Medooza operator=(const Medooza&) = delete;

};

class Minotaur : public Myth_Creature
{
public:
	static Minotaur& Instance()
	{
		static Minotaur theSingleInstance;
		return theSingleInstance;
	}

private:
	Minotaur(){
		this->set_color("brown");
		this->set_size("3");
		this->set_mythology("greek");
		this->set_how_attack("hammer");
		this->set_env("man-bull");
		this->set_name("Minotaur");
		this->set_description("-");

	};
	Minotaur(const Minotaur& root) = delete;
	Minotaur operator=(const Minotaur&) = delete;

};





int main(int argc, char const *argv[])
{

	Medooza& medooza = Medooza::Instance();
	
	Minotaur& minotaur = Minotaur::Instance();
	minotaur.out_file();

	Myth_Creature mino2 = Myth_Creature();
	mino2.from_file("Minotaur");
	std::cout << mino2.get_name() << ":" << mino2.get_how_attack() << std::endl;

	Myth_Creature Thor = Myth_Creature();
	Thor.set_name("thor");
	Thor.set_how_attack(minotaur.get_how_attack());



	std::cout << medooza.get_name() << ":" << medooza.get_how_attack() << std::endl;
	std::cout << minotaur.get_name() << ":" << minotaur.get_how_attack()  << std::endl;
	std::cout << Thor.get_name() << ":" << Thor.get_how_attack() << std::endl;

}