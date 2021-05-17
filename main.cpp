//
//  main.cpp
//  gamechallenge
//
//  Created by amir  on 5/13/21.
//

#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>

using namespace std ;

class team ;
class movements
{
    friend class team ;
    friend istream &operator >> (istream &input , team &player_team ) ;
    friend bool pass (team player[2],int first, int second);
    friend bool dribble (team player[2],int first, int second);
    friend bool shoot (team player[2],int first, int second) ;
    public :
    
    void default_accuracy (int option)
    {
        switch (option)
        {
            case 1 :// exellent at attack
                shoot_accuracy = 86 ;
                pass_accuracy = 62 ;
                tackle_accuracy = 79 ;
                dribble_accuracy = 89 ;
                save_accuracy = 87 ;
                
                break;
                
            case 2 :// exellent at defend
                shoot_accuracy = 89 ;
                pass_accuracy = 66 ;
                tackle_accuracy = 90 ;
                dribble_accuracy = 80 ;
                save_accuracy = 91 ;
                break;
                
            case 3 :// good at both
                shoot_accuracy = 88 ;
                pass_accuracy = 64 ;
                tackle_accuracy = 85 ;
                dribble_accuracy = 84 ;
                save_accuracy = 89 ;
                break;
                
            default:
                break;
        }
    }
    
    private :
    
    // accuracy
    int shoot_accuracy ;
    int pass_accuracy ;
    int tackle_accuracy ;
    int dribble_accuracy ;
    int save_accuracy ;
    
    // GEM
    int shoot_GEM = 3 ;
    int pass_GEM = 1 ;
    int tackle_GEM = 2 ;
    int dribble_GEM = 2 ;
    int save_GEM = 3 ;
    
};

class team
{
    friend istream &operator >> (istream &inputt , team &player_team ) ;
    friend class movements ;
    friend void selecting_team (team player_team) ;
    friend bool pass (team player[2],int first, int second);
    friend bool dribble (team player[2],int first, int second);
    friend bool shoot (team player[2],int first, int second) ;
    public :
    
    bool set_as_first()
    {
        first = true;
        return first ;
    }
    
    
    void complete (int team_number)
    {
        switch ( team_number )
        {
            case 1 ://team 1 (REAL MADRID)
            {
//                name_setter("REAL MADRID") ;
                name = "REAL MADRID";
                move.shoot_accuracy = 88 ;
                move.pass_accuracy = 65 ;
                move.tackle_accuracy = 93 ;
                move.dribble_accuracy = 80 ;
                move.save_accuracy = 89 ;
                break;
            }
            case 2 ://team 2 (FC BARCELONA)
            {
//                name_setter("FC BARCELONA");
                name = "FC BARCELONA";
                move.shoot_accuracy = 82 ;
                move.pass_accuracy = 66 ;
                move.tackle_accuracy = 72 ;
                move.dribble_accuracy = 85 ;
                move.save_accuracy = 90 ;
                break;
            }
            case 3 ://team 3 (juventus)
            {
                name = "juventus";
                move.shoot_accuracy = 85 ;
                move.pass_accuracy = 60 ;
                move.tackle_accuracy = 87 ;
                move.dribble_accuracy = 75 ;
                move.save_accuracy = 90 ;
                break;
            }
                
            case 4 ://team 4 (bayern munich)
            {
                name = "bayern munich";
                move.shoot_accuracy = 95 ;
                move.pass_accuracy = 70 ;
                move.tackle_accuracy = 90 ;
                move.dribble_accuracy = 87 ;
                move.save_accuracy = 95 ;
                break;
            }
            case 5 ://team 5 (PARIS SAINT-GERMAIN)
            {
                name = "PARIS SAINT-GERMAIN";
                move.shoot_accuracy = 90 ;
                move.pass_accuracy = 63 ;
                move.tackle_accuracy = 86 ;
                move.dribble_accuracy = 93 ;
                move.save_accuracy = 85 ;
                break;
            }
            default:
                break;

        }
    }
   
    void add_gems(int round)
    {
        if ( round <= 2 )
            GEMS+=10;
        else
            GEMS+=5;
    }
    
    string name_getter(){
	this -> name = name;
	return name;
	}
    
//    void name_setter(string *a)
//    {
//        name = *a ;
//    }
    
    void goal_setter(){goals++;}
    
    int goal_getter(){return goals;}
    
    int GEM_getter(){return GEMS;}
    
    private :
    
    string name ;
    movements move ;
    bool first = false ;
    int GEMS = 0 ;
    int goals = 0 ;
    
};



//movements functions
bool pass (team player[2],int first, int second)
{
    static int accuracy ; // javad changed on 5/17/21
    char react_move ;
    
    player[first].GEMS-=player[first].move.pass_GEM;
    
    cout << player[second].name<<"turn \n\t\t\t\t"<<player[second].GEMS;
    cout << "\n--------------------------------\n";
    cout << "press < T > key to tackle or < L > to let ball go ...\n";
    cout << "--------------------------------\n";
    
    cin >> react_move ;
    
    if (react_move=='L'||react_move=='l')
        return true ;
    else
    {
        player[second].GEMS-=player[second].move.tackle_GEM;
        accuracy = (player[first].move.pass_accuracy/2+(100-player[second].move.tackle_accuracy)/2);// change it ..
        if (rand()%100<=accuracy)
            return true ;
        else
            return false ;
    }
}

bool dribble (team player[2],int first, int second)
{
    static int accuracy ; // javad changed on 5/17/21
    char react_move ;
    
    player[first].GEMS-=player[first].move.dribble_GEM;
    
    cout << player[1].name<<"turn \n\t\t\t\t"<<player[second].GEMS;
    cout << "\n--------------------------------\n";
    cout << "press < T > key to tackle or < L > to let ball go ...\n";
    cout << "--------------------------------\n";
    cin >> react_move ;
    if (react_move=='L'||react_move=='l')
        return true ;
    else
    {
        player[second].GEMS-=player[second].move.tackle_GEM;
        accuracy = (player[first].move.dribble_accuracy/2+(100-player[second].move.tackle_accuracy)/2);// change it ..
        if (rand()%100<=accuracy)
            return true ;
        else
            return false ;
    }
}

bool shoot (team player[2],int first, int second)
{
    static int accuracy ; // javad changed on 5/17/21
    char react_move ;
    
    player[first].GEMS-=player[first].move.shoot_GEM;
    
    cout << player[second].name<<"turn \n\t\t\t\t"<<player[second].GEMS;
    cout << "\n--------------------------------\n";
    cout << "press < S > key to save ...\n";
    cout << "--------------------------------\n";
    
    cin >> react_move ;
    
    if (react_move=='S'||react_move=='s')
    {
        player[second].GEMS-=player[second].move.save_GEM;
        accuracy = (player[first].move.shoot_accuracy/2+(100-player[second].move.save_accuracy)/2);// change it ..
        
        if (rand()%100<=accuracy)
            return true ;
        else
            return false ;
    }
    else
    {
        if (rand()%100<=(player[first].move.shoot_accuracy))
            return true ;
        else
            return false ;
    }
}

void selecting_team (team player_team)
{

    int input ;
    cin >> input ;
    if ( input==6)
        cin >> player_team ;
    else
        player_team.complete(input);
}

istream &operator >> (istream &input , team &player_team )
{
    int chose ;
    input >> player_team.name ;
    cout << "--------\n";// three option
    input >> chose ;
    player_team.move.default_accuracy(chose);
    return input ;
}

void change (int *first , int *second )
{
    *second = *first + *second ;
    *first = *second - *first ;
    *second = *second - *first ;
}

int main()
{
    srand(time(0));
    
    string menu ;
    int first ;
    int second ;
    int stage ;
    int round ;
    char input ;
    char movement ;
    
    team player_team[2];// player 1 : player_team[0] , player 2 : player_team[1]
    
    // explaining the game
    cout << "\n\t\t\tWELCOME TO GEMBALL\n\nTo receive instruction press 9 otherwise press any key..\n\n";
    
    cin >> menu ;

    if (menu == "9")
    {
        cout << "-----\n";// the instuction
        cin >> menu ;
    }
    do
    {
        
        // print the team list
        
        cout << "\nTEAM LIST :";
        cout << "\n\n\t1.Real madrid           authority : defend        overall : 87%";// change the overall
        cout << "\n\n\t2.Fc barcelona          authority : attack        overall : 83%";
        cout << "\n\n\t3.Juventus              authority : defend        overall : 84%";
        cout << "\n\n\t4.Bayern munich         authority : defend        overall : 92%";
        cout << "\n\n\t5.Paris saint-germain   authority : attack        overall : 88%";
        cout << "\n\n\t6.My own team \n\n";
        
        cout << "Chose the first team (player 1)\n";
        int input ;
	    cin >> input ;
	    if ( input==6)
	        cin >> player_team[0] ;
	    else
        player_team[0].complete(input);
        //selecting_team ( player_team[0]) ;// javad changed on 5/17/21
//        cout << player_team[0].name_getter() << endl;
        cout << "Chose the second team (player 2)\n";
	    cin >> input ;
	    if ( input==6)
	        cin >> player_team[1] ;
	    else
	        player_team[1].complete(input);
        //selecting_team ( player_team[1]) ; // javad changed on 5/17/21
//        cout << player_team[1].name_getter() << endl;
        
        cout << "Press entre to START\n";
        cin >> menu ;
        
        if (rand()%2 == 0)
        {
            player_team[0].set_as_first();
            cout << "Team 1 starts\n";
            first = 0 ;
            second = 1 ;
        }
        else
        {
            player_team[1].set_as_first();
            cout << "Team 2 starts\n";
            first = 1 ;
            second = 0 ;
        }
        do
        {
            for ( round = 1 ; round <= 4 ; round ++ )
            {
                cout << "ROUND " << round << endl ;
                
                player_team[0].add_gems(round);
                player_team[1].add_gems(round);
                
                cout <<"player1 ("<< player_team[0].name_getter()<<") got "<<player_team[0].GEM_getter()<<" gems \n";
                cout <<"player2 ("<< player_team[1].name_getter()<<") got "<<player_team[1].GEM_getter()<<" gems \n";
                
                    for ( stage = 1 ; stage<=4 ; stage++ )
                    {
                        cout << "stage : "<< stage << endl;
                        if (stage == 4)// shoooot stage :)
                        {
                            cout << player_team[first].name_getter()<<"turn \t\t\t\t"<<player_team[first].GEM_getter();
                            cout << "\n--------------------------------\n";
                            cout << "Press < S > to shoot.. \n";
                            cout << "--------------------------------\n";
                            
                            cin >> movement ;// first player move
                            if ( movement == 'S' || movement == 's' )
                            {
                                if (shoot(player_team, first, second)==false)
                                    cout << player_team[second].name_getter()<<" save the ball .. \n";
                    
                                else
                                {
                                    player_team[first].goal_setter();
                                    cout << "\n\n\t\tGOOOOOOOOOOOOOOOOOOOOOL\n\n";
                                }
                            }
                            break;
                        }
                        cout << player_team[first].name_getter()<<"turn \t\t\t\t"<<player_team[first].GEM_getter();
                        cout << "\n--------------------------------\n";
                        cout << "Press < P > to pass or < D > to dribble \n";
                        cout << "--------------------------------\n";
                        
                        cin >> movement ;// first player move
                        
                        if (movement == 'P' || movement == 'p')
                        {
                            if( pass(player_team,first,second) == false )
                            {
                                change(&first,&second);
        //                        stage = 1 ;
                            }
                        }
                        else if (movement == 'D' || movement == 'd')
                        {
                            if( dribble(player_team,first,second) == false )
                            {
                                change(&first,&second);
        //                        stage = 1 ;
                            }
                        }
                        
                    }
                change(&first,&second);
                
                cout << player_team[0].name_getter() << "\t" <<player_team[0].goal_getter()<<"\t-\t";
                cout << player_team[1].goal_getter() << "\t" <<player_team[1].name_getter()<<endl;
                
                cout << "ROUND " << round << " finished \npree < C > to continue \n";
                cin >> movement ;
            }
            if (player_team[0].goal_getter()>player_team[1].goal_getter())
                cout << player_team[0].name_getter()<<" won \n";
            else if (player_team[1].goal_getter()>player_team[0].goal_getter())
                cout << player_team[1].name_getter()<<" won \n";
            else
                cout << "------\n";
            
            cout << "-----\n";//rematch ...
            cout << "-----\n";//selecting teams ...
            cout << "-----\n";//finish ...
                
            cin >> input ;
            
        }while(input == 'R' || input == 'r');// rematch ..
    }while(input == 'S' || input == 's');// selecting teams ..
    
    cout << "------\n";
    
    return 0;
}

