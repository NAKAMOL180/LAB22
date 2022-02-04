#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<iomanip>

using namespace std;

class Unit{
		string name;
		string type;	//hero or monster	
		int hp;
		int hpmax;
		int atk;
		int def;
		bool guard_on;		
	public:			
		void create(string);
		void showStatus();
		void newTurn();
		int attack(Unit &); //write
		int beAttacked(int); //write
		int heal();	 //write check heal more than hp max hp=hpmax else heal mai gern hp got hp = hp+kahheal return heal;
		void guard(); //write
		bool isDead();	//write
};

void Unit::create(string t){ 
	if(t == "Hero"){
		type = "Hero";
		cout << "Please input your name: ";
		getline(cin,name);
		hpmax = rand()%20+90; // 0 - 19 + 90
		atk = rand()%5+14;
		def = rand()%3+9;
	}else if(t == "Monster"){
		type = "Monster";
		name = "Kraken";
		hpmax = rand()%20+200;
		atk = rand()%5+25;
		def = rand()%3+5;
	}
	hp = hpmax; //พลังเต็ม
	guard_on = false; //สถานะยูนิตนั้น การ์ดอยู่รึเปล่า เริ่มไม่การ์ด
}

void Unit::showStatus(){ //หน้าโชวสเตตัส
	if(type == "Hero"){
		cout << "---------------------------------------\n"; 
		cout << name << "\n"; 
		cout << "HP: " << hp << "/" << hpmax << "\tATK: "<< atk << "\t\tDEF: "<< def;		
		cout << "\n---------------------------------------\n";
	}	
	else if(type == "Monster"){
		cout << "\t\t\t\t---------------------------------------\n"; 
		cout << "\t\t\t\t" << name << "\n"; 
		cout << "\t\t\t\tHP: " << hp << "\t\tATK: "<< atk << "\t\tDEF: "<< def;
		cout << "\n\t\t\t\t---------------------------------------\n";
	}
}

void Unit::newTurn(){ //ไม่ต้องแก้
	guard_on = false;
}

int Unit::attack(Unit &monA);{
	return  monA.beAttack(atk);
} //attack

int Unit::beAttacked(int oppatk);{
	int final_oppatk;
	if(guard_on == false){
		final_oppatk = oppatk-def;
	}else{
		final_oppatk = (oppatk-def)/3;
		
	}
	hp -= final_oppatk;
	return final_oppatk;
} // was attacked

int heal(){
	int i = hpmax - hp;
    int healhp =  rand()%21 + 10;
    if(healhp >= i) healhp = i;
    hp = hp + healhp;
    return healhp;
}	//check heal

void Unit::guard(){
	guard_on = true;
} 

bool Unit::isDead(){
	if(hp <= 0 )
		return true;
	else 
		return false;
} // check death



/////////////////////////////////////////////////////////////////////////////////////
//Write function members isDead(), guard(), heal(), beAttacked(), and attack() here//
/////////////////////////////////////////////////////////////////////////////////////



void drawScene(char p_action,int p,char m_action,int m){ //ไม่ต้องแก้ วาดscene
	cout << "                                                       \n";
	if(p_action == 'A'){
	cout << "                                       "<< -p <<"\n";
	}else{
	cout << "                                                       \n";	
	}	
	cout << "                                *               *      \n";
	cout << "                                **  *********  **      \n";
	cout << "                                ****         ****      \n";
	if(m_action == 'A'){
	cout << "                 " << setw(5) << -m << "           *** **   ** ***       Attack!\n";
	}else if(m_action == 'G'){
	cout << "                                 *** **   ** ***       Guard!\n";
	}else{
	cout << "                                 *** **   ** ***       \n";	
	}
	cout << "                                  ** **   ** **        \n";
	cout << "                   ***             *         *         \n";
	if(p_action == 'A'){
	cout << "        Attack!    ***  *           *********          \n";		
	}else if(p_action == 'H'){
	cout << "      Heal! +" << setw(2) << p << "    ***  *           *********          \n";
	}else if(p_action == 'G'){
	cout << "         Guard!    ***  *           *********          \n";
	}else{
	cout << "                   ***  *           *********          \n";	
	}
	cout << "                    *  *       ***  *  *  *            \n";
	cout << "                  *****           **   *   *           \n";
	cout << "                    *                  *    ***        \n";
	cout << "                   * *               **        *       \n";
	cout << "                  *   *                                \n";
	cout << "                                                       \n";
};


void playerWin(){	
	cout << "*******************************************************\n";
	for(int i = 0; i < 3; i++) cout << "*                                                     *\n";
	cout << "*                   YOU WIN!!!                        *\n";
	for(int i = 0; i < 3; i++) cout << "*                                                     *\n";
	cout << "*******************************************************\n";
};


void playerLose(){
	cout << "*******************************************************\n";
	cout << "*                                                     *\n";
	cout << "*                   YOU LOSE!!!                       *\n";
	cout << "*                                                     *\n";
	cout << "*******************************************************\n";
};
