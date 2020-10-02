#include <iostream>
#include <time.h>
using namespace std;
void game_info()
{
	char a;
	system("cls");
	cout<<"\n Information"<<endl<<endl;
	cout<<" Characters"<<endl;
	cout<<"  "<<char(2)<<" - Player"<<endl;
	cout<<"  "<<char(1)<<" - Computer"<<endl;
	cout<<endl;
	cout<<" Barriers and mines"<<endl;
	cout<<"  "<<char(219)<<" - Steel barrier (you can't get through it)"<<endl;
	cout<<"  "<<char(176)<<" - Brick barrier (you can break it by shot)"<<endl;
	cout<<"  "<<char(15)<<" - Mine (be very carefool, and you can't destroy it)"<<endl;
	cout<<endl;
	cout<<" Actions"<<endl;
	cout<<"  i - Move top"<<endl;
	cout<<"  j - Move left"<<endl;
	cout<<"  l - Move right"<<endl;
	cout<<"  k - Move back"<<endl;
	cout<<"  s - Shot"<<endl;
	cout<<"  e - Information"<<endl;
	cout<<endl;
	cout<<" Shooting"<<endl;
	cout<<"  "<<char(249)<<" - Bullet (you shoot in the direction of your last move)"<<endl;
	cout<<"  Tip : Do not shoot in barrier just near it, or you'll be killed by a blast."<<endl;
	cout<<"  For example : you trying to make a left shot in a brick barrier "<<char(2)<<char(176)<<endl;
	cout<<"  Result : you destroyed the brick barrier and yourself!!!"<<endl;
	cout<<endl;
	cout<<" Press any key to continue ";
	cin>>a;
}
void game_map(int user_x,int user_y,int comp_x,int comp_y,char field[][31])
{
	int point;
	for (int i=0;i<20;i++)
	{
		for (int j=0;j<31;j++)
		{
			point=rand()%15;
			if (point==0||point==1||point==6||point==7||point==8||point==9||point==10||point==11||point==12||point==13||point==14)
				field[i][j]=char(255);
			else if (point==2)
				field[i][j]=char(219);
			else if (point==3)
				field[i][j]=char(15);
			else if (point==4||point==5)
				field[i][j]=char(176);
		}
	}
	field[user_x][user_y]=char(2);
	field[comp_x][comp_y]=char(1);
}
void screen_refresh (char field[][31])
{
	system("cls");
	cout<<"\n ";
	for (int t=0;t<33;t++)
	    cout<<char(219);
	cout<<endl;
    for (int i=0;i<20;i++)
    {
        cout<<" "<<char(219);
		for (int j=0;j<31;j++)
			cout<<field[i][j];
        cout<<char(219)<<endl;
	}
	cout<<" ";
	for (int t=0;t<33;t++)
		cout<<char(219);
	cout<<"\n\n";
}
void user_move_top(int user_x,int user_y,char field[][31])
{
	field[user_x][user_y]=char(255);
	user_x--;
	field[user_x][user_y]=char(2);
}
void user_top_mine(int user_x,int user_y,char field[][31])
{
    field[user_x][user_y]=char(255);
	user_x--;
	field[user_x][user_y]=char(255);
}
void user_move_left(int user_x,int user_y,char field[][31])
{
	field[user_x][user_y]=char(255);
	user_y--;
	field[user_x][user_y]=char(2);
}
void user_left_mine(int user_x,int user_y,char field[][31])
{
	field[user_x][user_y]=char(255);
	user_y--;
	field[user_x][user_y]=char(255);
}
void user_move_right(int user_x,int user_y,char field[][31])
{
	field[user_x][user_y]=char(255);
	user_y++;
	field[user_x][user_y]=char(2);
}
void user_right_mine(int user_x,int user_y,char field[][31])
{
	field[user_x][user_y]=char(255);
	user_y++;
	field[user_x][user_y]=char(255);
}
void user_move_back(int user_x,int user_y,char field[][31])
{
	field[user_x][user_y]=char(255);
	user_x++;
	field[user_x][user_y]=char(2);
}
void user_back_mine(int user_x,int user_y,char field[][31])
{
    field[user_x][user_y]=char(255);
	user_x++;
	field[user_x][user_y]=char(255);
}
int user_top_shot(int user_bullet_x,int user_bullet_y,char field[][31])
{
	if (user_bullet_x==0)
	{
		field[user_bullet_x][user_bullet_y]=char(255);
		return 0;
	}
	else if (field[user_bullet_x-1][user_bullet_y]==char(255))
	{
		if (field[user_bullet_x][user_bullet_y]==char(2))
	    {
		    user_bullet_x=user_bullet_x-1;
		    field[user_bullet_x][user_bullet_y]=char(249);
	    }
	    else if (field[user_bullet_x][user_bullet_y]!=char(2))
	    {
	        field[user_bullet_x][user_bullet_y]=char(255);
	        user_bullet_x=user_bullet_x-1;
	        field[user_bullet_x][user_bullet_y]=char(249);
	    }
	}
	else if (field[user_bullet_x-1][user_bullet_y]==char(219))
	{
		if (field[user_bullet_x][user_bullet_y]==char(2))
	    {
		    field[user_bullet_x][user_bullet_y]=char(255);
		}
	    else if (field[user_bullet_x][user_bullet_y]!=char(2))
	    {
	        field[user_bullet_x][user_bullet_y]=char(255);
	    }
		return 0;
	}
	else if (field[user_bullet_x-1][user_bullet_y]==char(176))
	{
		if (field[user_bullet_x][user_bullet_y]==char(2))
	    {
		    field[user_bullet_x][user_bullet_y]=char(255);
			field[user_bullet_x-1][user_bullet_y]=char(255);
	    }
	    else if (field[user_bullet_x][user_bullet_y]!=char(2))
	    {
	        field[user_bullet_x][user_bullet_y]=char(255);
			field[user_bullet_x-1][user_bullet_y]=char(255);
	    }
		return 0;
	}
	else if (field[user_bullet_x-1][user_bullet_y]==char(1))
	{
		if (field[user_bullet_x][user_bullet_y]==char(2))
	    {
		    field[user_bullet_x][user_bullet_y]=char(255);
			field[user_bullet_x-1][user_bullet_y]=char(255);
	    }
	    else if (field[user_bullet_x][user_bullet_y]!=char(2))
	    {
	        field[user_bullet_x][user_bullet_y]=char(255);
			field[user_bullet_x-1][user_bullet_y]=char(255);
	    }
		return 0;
	}
	else if (field[user_bullet_x-1][user_bullet_y]==char(15))
	{
		if (field[user_bullet_x][user_bullet_y]==char(2))
	    {
		    user_bullet_x=user_bullet_x-2;
		    field[user_bullet_x][user_bullet_y]=char(249);
	    }
	    else if (field[user_bullet_x][user_bullet_y]!=char(2))
	    {
	        field[user_bullet_x][user_bullet_y]=char(255);
	        user_bullet_x=user_bullet_x-2;
	        field[user_bullet_x][user_bullet_y]=char(249);
	    }
	}
}
int user_right_shot(int user_bullet_x,int user_bullet_y,char field[][31])
{
	if (user_bullet_y==30)
	{
		field[user_bullet_x][user_bullet_y]=char(255);
		return 0;
	}
	else if (field[user_bullet_x][user_bullet_y+1]==char(255))
	{
		if (field[user_bullet_x][user_bullet_y]==char(2))
	    {
		    user_bullet_y++;
		    field[user_bullet_x][user_bullet_y]=char(249);
	    }
	    else if (field[user_bullet_x][user_bullet_y]!=char(2))
	    {
	        field[user_bullet_x][user_bullet_y]=char(255);
	        user_bullet_y++;
	        field[user_bullet_x][user_bullet_y]=char(249);
	    }
	}
	else if (field[user_bullet_x][user_bullet_y+1]==char(219))
	{
		if (field[user_bullet_x][user_bullet_y]==char(2))
	    {
		    field[user_bullet_x][user_bullet_y]=char(255);
		}
	    else if (field[user_bullet_x][user_bullet_y]!=char(2))
	    {
	        field[user_bullet_x][user_bullet_y]=char(255);
	    }
		return 0;
	}
	else if (field[user_bullet_x][user_bullet_y+1]==char(176))
	{
		if (field[user_bullet_x][user_bullet_y]==char(2))
	    {
		    field[user_bullet_x][user_bullet_y]=char(255);
			field[user_bullet_x][user_bullet_y+1]=char(255);
	    }
	    else if (field[user_bullet_x][user_bullet_y]!=char(2))
	    {
	        field[user_bullet_x][user_bullet_y]=char(255);
			field[user_bullet_x][user_bullet_y+1]=char(255);
	    }
		return 0;
	}
	else if (field[user_bullet_x][user_bullet_y+1]==char(1))
	{
		if (field[user_bullet_x][user_bullet_y]==char(2))
	    {
		    field[user_bullet_x][user_bullet_y]=char(255);
			field[user_bullet_x][user_bullet_y+1]=char(255);
	    }
	    else if (field[user_bullet_x][user_bullet_y]!=char(2))
	    {
	        field[user_bullet_x][user_bullet_y]=char(255);
			field[user_bullet_x][user_bullet_y+1]=char(255);
	    }
		return 0;
	}
	else if (field[user_bullet_x][user_bullet_y+1]==char(15))
	{
		if (field[user_bullet_x][user_bullet_y]==char(2))
	    {
		    user_bullet_y+=2;
		    field[user_bullet_x][user_bullet_y]=char(249);
	    }
	    else if (field[user_bullet_x][user_bullet_y]!=char(2))
	    {
	        field[user_bullet_x][user_bullet_y]=char(255);
	        user_bullet_y+=2;
	        field[user_bullet_x][user_bullet_y]=char(249);
	    }
	}
}
int user_back_shot(int user_bullet_x,int user_bullet_y,char field[][31])
{
	if (user_bullet_x==19)
	{
		field[user_bullet_x][user_bullet_y]=char(255);
		return 0;
	}
	else if (field[user_bullet_x+1][user_bullet_y]==char(255))
	{
		if (field[user_bullet_x][user_bullet_y]==char(2))
	    {
		    user_bullet_x++;
		    field[user_bullet_x][user_bullet_y]=char(249);
	    }
	    else if (field[user_bullet_x][user_bullet_y]!=char(2))
	    {
	        field[user_bullet_x][user_bullet_y]=char(255);
	        user_bullet_x++;
	        field[user_bullet_x][user_bullet_y]=char(249);
	    }
	}
	else if (field[user_bullet_x+1][user_bullet_y]==char(219))
	{
		if (field[user_bullet_x][user_bullet_y]==char(2))
	    {
		    field[user_bullet_x][user_bullet_y]=char(255);
		}
	    else if (field[user_bullet_x][user_bullet_y]!=char(2))
	    {
	        field[user_bullet_x][user_bullet_y]=char(255);
	    }
		return 0;
	}
	else if (field[user_bullet_x+1][user_bullet_y]==char(176))
	{
		if (field[user_bullet_x][user_bullet_y]==char(2))
	    {
		    field[user_bullet_x][user_bullet_y]=char(255);
			field[user_bullet_x+1][user_bullet_y]=char(255);
	    }
	    else if (field[user_bullet_x][user_bullet_y]!=char(2))
	    {
	        field[user_bullet_x][user_bullet_y]=char(255);
			field[user_bullet_x+1][user_bullet_y]=char(255);
	    }
		return 0;
	}
	else if (field[user_bullet_x+1][user_bullet_y]==char(1))
	{
		if (field[user_bullet_x][user_bullet_y]==char(2))
	    {
		    field[user_bullet_x][user_bullet_y]=char(255);
			field[user_bullet_x+1][user_bullet_y]=char(255);
	    }
	    else if (field[user_bullet_x][user_bullet_y]!=char(2))
	    {
	        field[user_bullet_x][user_bullet_y]=char(255);
			field[user_bullet_x+1][user_bullet_y]=char(255);
	    }
		return 0;
	}
	else if (field[user_bullet_x+1][user_bullet_y]==char(15))
	{
		if (field[user_bullet_x][user_bullet_y]==char(2))
	    {
		    user_bullet_x+=2;
		    field[user_bullet_x][user_bullet_y]=char(249);
	    }
	    else if (field[user_bullet_x][user_bullet_y]!=char(2))
	    {
	        field[user_bullet_x][user_bullet_y]=char(255);
	        user_bullet_x+=2;
	        field[user_bullet_x][user_bullet_y]=char(249);
	    }
	}
}
int user_left_shot(int user_bullet_x,int user_bullet_y,char field[][31])
{
	if (user_bullet_y==0)
	{
		field[user_bullet_x][user_bullet_y]=char(255);
		return 0;
	}
	else if (field[user_bullet_x][user_bullet_y-1]==char(255))
	{
		if (field[user_bullet_x][user_bullet_y]==char(2))
	    {
		    user_bullet_y--;
		    field[user_bullet_x][user_bullet_y]=char(249);
	    }
	    else if (field[user_bullet_x][user_bullet_y]!=char(2))
	    {
	        field[user_bullet_x][user_bullet_y]=char(255);
	        user_bullet_y--;
	        field[user_bullet_x][user_bullet_y]=char(249);
	    }
	}
	else if (field[user_bullet_x][user_bullet_y-1]==char(219))
	{
		if (field[user_bullet_x][user_bullet_y]==char(2))
	    {
		    field[user_bullet_x][user_bullet_y]=char(255);
		}
	    else if (field[user_bullet_x][user_bullet_y]!=char(2))
	    {
	        field[user_bullet_x][user_bullet_y]=char(255);
	    }
		return 0;
	}
	else if (field[user_bullet_x][user_bullet_y-1]==char(176))
	{
		if (field[user_bullet_x][user_bullet_y]==char(2))
	    {
		    field[user_bullet_x][user_bullet_y]=char(255);
			field[user_bullet_x][user_bullet_y-1]=char(255);
	    }
	    else if (field[user_bullet_x][user_bullet_y]!=char(2))
	    {
	        field[user_bullet_x][user_bullet_y]=char(255);
			field[user_bullet_x][user_bullet_y-1]=char(255);
	    }
		return 0;
	}
	else if (field[user_bullet_x][user_bullet_y-1]==char(1))
	{
		if (field[user_bullet_x][user_bullet_y]==char(2))
	    {
		    field[user_bullet_x][user_bullet_y]=char(255);
			field[user_bullet_x][user_bullet_y-1]=char(255);
	    }
	    else if (field[user_bullet_x][user_bullet_y]!=char(2))
	    {
	        field[user_bullet_x][user_bullet_y]=char(255);
			field[user_bullet_x][user_bullet_y-1]=char(255);
	    }
		return 0;
	}
	else if (field[user_bullet_x][user_bullet_y-1]==char(15))
	{
		if (field[user_bullet_x][user_bullet_y]==char(2))
	    {
		    user_bullet_y-=2;
		    field[user_bullet_x][user_bullet_y]=char(249);
	    }
	    else if (field[user_bullet_x][user_bullet_y]!=char(2))
	    {
	        field[user_bullet_x][user_bullet_y]=char(255);
	        user_bullet_y-=2;
	        field[user_bullet_x][user_bullet_y]=char(249);
	    }
	}
}
void comp_move_top(int comp_x,int comp_y,char field[][31])
{
	field[comp_x][comp_y]=char(255);
	comp_x--;
	field[comp_x][comp_y]=char(1);
}
void comp_move_left(int comp_x,int comp_y,char field[][31])
{
	field[comp_x][comp_y]=char(255);
	comp_y--;
	field[comp_x][comp_y]=char(1);
}
void comp_move_right(int comp_x,int comp_y,char field[][31])
{
	field[comp_x][comp_y]=char(255);
	comp_y++;
	field[comp_x][comp_y]=char(1);
}
void comp_move_back(int comp_x,int comp_y,char field[][31])
{
	field[comp_x][comp_y]=char(255);
	comp_x++;
	field[comp_x][comp_y]=char(1);
}
int comp_top_shot(int comp_bullet_x,int comp_bullet_y,char field[][31])
{
	if (comp_bullet_x==0)
	{
		field[comp_bullet_x][comp_bullet_y]=char(255);
		return 0;
	}
	else if (field[comp_bullet_x-1][comp_bullet_y]==char(255))
	{
		if (field[comp_bullet_x][comp_bullet_y]==char(1))
	    {
		    comp_bullet_x--;
		    field[comp_bullet_x][comp_bullet_y]=char(249);
	    }
	    else if (field[comp_bullet_x][comp_bullet_y]!=char(1))
	    {
	        field[comp_bullet_x][comp_bullet_y]=char(255);
	        comp_bullet_x--;
	        field[comp_bullet_x][comp_bullet_y]=char(249);
	    }
	}
	else if (field[comp_bullet_x-1][comp_bullet_y]==char(219))
	{
		if (field[comp_bullet_x][comp_bullet_y]==char(1))
	    {
		    field[comp_bullet_x][comp_bullet_y]=char(255);
		}
	    else if (field[comp_bullet_x][comp_bullet_y]!=char(1))
	    {
	        field[comp_bullet_x][comp_bullet_y]=char(255);
	    }
		return 0;
	}
	else if (field[comp_bullet_x-1][comp_bullet_y]==char(176))
	{
		if (field[comp_bullet_x][comp_bullet_y]==char(1))
	    {
		    field[comp_bullet_x][comp_bullet_y]=char(255);
			field[comp_bullet_x-1][comp_bullet_y]=char(255);
	    }
	    else if (field[comp_bullet_x][comp_bullet_y]!=char(1))
	    {
	        field[comp_bullet_x][comp_bullet_y]=char(255);
			field[comp_bullet_x-1][comp_bullet_y]=char(255);
	    }
		return 0;
	}
	else if (field[comp_bullet_x-1][comp_bullet_y]==char(2))
	{
		if (field[comp_bullet_x][comp_bullet_y]==char(1))
	    {
		    field[comp_bullet_x][comp_bullet_y]=char(255);
			field[comp_bullet_x-1][comp_bullet_y]=char(255);
	    }
	    else if (field[comp_bullet_x][comp_bullet_y]!=char(1))
	    {
	        field[comp_bullet_x][comp_bullet_y]=char(255);
			field[comp_bullet_x-1][comp_bullet_y]=char(255);
	    }
		return 0;
	}
	else if (field[comp_bullet_x-1][comp_bullet_y]==char(15))
	{
		if (field[comp_bullet_x][comp_bullet_y]==char(1))
	    {
		    comp_bullet_x-=2;
		    field[comp_bullet_x][comp_bullet_y]=char(249);
	    }
	    else if (field[comp_bullet_x][comp_bullet_y]!=char(1))
	    {
	        field[comp_bullet_x][comp_bullet_y]=char(255);
	        comp_bullet_x-=2;
	        field[comp_bullet_x][comp_bullet_y]=char(249);
	    }
	}
}
int comp_left_shot(int comp_bullet_x,int comp_bullet_y,char field[][31])
{
	if (comp_bullet_y==0)
	{
		field[comp_bullet_x][comp_bullet_y]=char(255);
		return 0;
	}
	else if (field[comp_bullet_x][comp_bullet_y-1]==char(255))
	{
		if (field[comp_bullet_x][comp_bullet_y]==char(1))
	    {
		    comp_bullet_y--;
		    field[comp_bullet_x][comp_bullet_y]=char(249);
	    }
	    else if (field[comp_bullet_x][comp_bullet_y]!=char(1))
	    {
	        field[comp_bullet_x][comp_bullet_y]=char(255);
	        comp_bullet_y--;
	        field[comp_bullet_x][comp_bullet_y]=char(249);
	    }
	}
	else if (field[comp_bullet_x][comp_bullet_y-1]==char(219))
	{
		if (field[comp_bullet_x][comp_bullet_y]==char(1))
	    {
		    field[comp_bullet_x][comp_bullet_y]=char(255);
		}
	    else if (field[comp_bullet_x][comp_bullet_y]!=char(1))
	    {
	        field[comp_bullet_x][comp_bullet_y]=char(255);
	    }
		return 0;
	}
	else if (field[comp_bullet_x][comp_bullet_y-1]==char(176))
	{
		if (field[comp_bullet_x][comp_bullet_y]==char(1))
	    {
		    field[comp_bullet_x][comp_bullet_y]=char(255);
			field[comp_bullet_x][comp_bullet_y-1]=char(255);
	    }
	    else if (field[comp_bullet_x][comp_bullet_y]!=char(1))
	    {
	        field[comp_bullet_x][comp_bullet_y]=char(255);
			field[comp_bullet_x][comp_bullet_y-1]=char(255);
	    }
		return 0;
	}
	else if (field[comp_bullet_x][comp_bullet_y-1]==char(2))
	{
		if (field[comp_bullet_x][comp_bullet_y]==char(1))
	    {
		    field[comp_bullet_x][comp_bullet_y]=char(255);
			field[comp_bullet_x][comp_bullet_y-1]=char(255);
	    }
	    else if (field[comp_bullet_x][comp_bullet_y]!=char(1))
	    {
	        field[comp_bullet_x][comp_bullet_y]=char(255);
			field[comp_bullet_x][comp_bullet_y-1]=char(255);
	    }
		return 0;
	}
	else if (field[comp_bullet_x][comp_bullet_y-1]==char(15))
	{
		if (field[comp_bullet_x][comp_bullet_y]==char(1))
	    {
		    comp_bullet_y-=2;
		    field[comp_bullet_x][comp_bullet_y]=char(249);
	    }
	    else if (field[comp_bullet_x][comp_bullet_y]!=char(1))
	    {
	        field[comp_bullet_x][comp_bullet_y]=char(255);
	        comp_bullet_y-=2;
	        field[comp_bullet_x][comp_bullet_y]=char(249);
	    }
	}
}
int comp_right_shot(int comp_bullet_x,int comp_bullet_y,char field[][31])
{
	if (comp_bullet_y==0)
	{
		field[comp_bullet_x][comp_bullet_y]=char(255);
		return 0;
	}
	else if (field[comp_bullet_x][comp_bullet_y+1]==char(255))
	{
		if (field[comp_bullet_x][comp_bullet_y]==char(1))
	    {
		    comp_bullet_y++;
		    field[comp_bullet_x][comp_bullet_y]=char(249);
	    }
	    else if (field[comp_bullet_x][comp_bullet_y]!=char(1))
	    {
	        field[comp_bullet_x][comp_bullet_y]=char(255);
	        comp_bullet_y++;
	        field[comp_bullet_x][comp_bullet_y]=char(249);
	    }
	}
	else if (field[comp_bullet_x][comp_bullet_y+1]==char(219))
	{
		if (field[comp_bullet_x][comp_bullet_y]==char(1))
	    {
		    field[comp_bullet_x][comp_bullet_y]=char(255);
		}
	    else if (field[comp_bullet_x][comp_bullet_y]!=char(1))
	    {
	        field[comp_bullet_x][comp_bullet_y]=char(255);
	    }
		return 0;
	}
	else if (field[comp_bullet_x][comp_bullet_y+1]==char(176))
	{
		if (field[comp_bullet_x][comp_bullet_y]==char(1))
	    {
		    field[comp_bullet_x][comp_bullet_y]=char(255);
			field[comp_bullet_x][comp_bullet_y+1]=char(255);
	    }
	    else if (field[comp_bullet_x][comp_bullet_y]!=char(1))
	    {
	        field[comp_bullet_x][comp_bullet_y]=char(255);
			field[comp_bullet_x][comp_bullet_y+1]=char(255);
	    }
		return 0;
	}
	else if (field[comp_bullet_x][comp_bullet_y+1]==char(2))
	{
		if (field[comp_bullet_x][comp_bullet_y]==char(1))
	    {
		    field[comp_bullet_x][comp_bullet_y]=char(255);
			field[comp_bullet_x][comp_bullet_y+1]=char(255);
	    }
	    else if (field[comp_bullet_x][comp_bullet_y]!=char(1))
	    {
	        field[comp_bullet_x][comp_bullet_y]=char(255);
			field[comp_bullet_x][comp_bullet_y+1]=char(255);
	    }
		return 0;
	}
	else if (field[comp_bullet_x][comp_bullet_y+1]==char(15))
	{
		if (field[comp_bullet_x][comp_bullet_y]==char(1))
	    {
		    comp_bullet_y+=2;
		    field[comp_bullet_x][comp_bullet_y]=char(249);
	    }
	    else if (field[comp_bullet_x][comp_bullet_y]!=char(1))
	    {
	        field[comp_bullet_x][comp_bullet_y]=char(255);
	        comp_bullet_y+=2;
	        field[comp_bullet_x][comp_bullet_y]=char(249);
	    }
	}
}
int comp_back_shot(int comp_bullet_x,int comp_bullet_y,char field[][31])
{
	if (comp_bullet_x==19)
	{
		field[comp_bullet_x][comp_bullet_y]=char(255);
		return 0;
	}
	else if (field[comp_bullet_x+1][comp_bullet_y]==char(255))
	{
		if (field[comp_bullet_x][comp_bullet_y]==char(1))
	    {
		    comp_bullet_x++;
		    field[comp_bullet_x][comp_bullet_y]=char(249);
	    }
	    else if (field[comp_bullet_x][comp_bullet_y]!=char(1))
	    {
	        field[comp_bullet_x][comp_bullet_y]=char(255);
	        comp_bullet_x++;
	        field[comp_bullet_x][comp_bullet_y]=char(249);
	    }
	}
	else if (field[comp_bullet_x+1][comp_bullet_y]==char(219))
	{
		if (field[comp_bullet_x][comp_bullet_y]==char(1))
	    {
		    field[comp_bullet_x][comp_bullet_y]=char(255);
		}
	    else if (field[comp_bullet_x][comp_bullet_y]!=char(1))
	    {
	        field[comp_bullet_x][comp_bullet_y]=char(255);
	    }
		return 0;
	}
	else if (field[comp_bullet_x+1][comp_bullet_y]==char(176))
	{
		if (field[comp_bullet_x][comp_bullet_y]==char(1))
	    {
		    field[comp_bullet_x][comp_bullet_y]=char(255);
			field[comp_bullet_x+1][comp_bullet_y]=char(255);
	    }
	    else if (field[comp_bullet_x][comp_bullet_y]!=char(1))
	    {
	        field[comp_bullet_x][comp_bullet_y]=char(255);
			field[comp_bullet_x+1][comp_bullet_y]=char(255);
	    }
		return 0;
	}
	else if (field[comp_bullet_x+1][comp_bullet_y]==char(2))
	{
		if (field[comp_bullet_x][comp_bullet_y]==char(1))
	    {
		    field[comp_bullet_x][comp_bullet_y]=char(255);
			field[comp_bullet_x+1][comp_bullet_y]=char(255);
	    }
	    else if (field[comp_bullet_x][comp_bullet_y]!=char(1))
	    {
	        field[comp_bullet_x][comp_bullet_y]=char(255);
			field[comp_bullet_x+1][comp_bullet_y]=char(255);
	    }
		return 0;
	}
	else if (field[comp_bullet_x+1][comp_bullet_y]==char(15))
	{
		if (field[comp_bullet_x][comp_bullet_y]==char(1))
	    {
		    comp_bullet_x+=2;
		    field[comp_bullet_x][comp_bullet_y]=char(249);
	    }
	    else if (field[comp_bullet_x][comp_bullet_y]!=char(1))
	    {
	        field[comp_bullet_x][comp_bullet_y]=char(255);
	        comp_bullet_x+=2;
	        field[comp_bullet_x][comp_bullet_y]=char(249);
	    }
	}
}
int top_shot_line(int comp_x,int comp_y,int user_x,char field[][31])
{
	comp_x--;
	for (int i=comp_x;i>user_x;i--)
	{
		if (field[i][comp_y]==char(219))
			return 0;
	}
}
int left_shot_line(int comp_x,int comp_y,int user_y,char field[][31])
{
	comp_y--;
	for (int i=comp_y;i>user_y;i--)
	{
		if (field[comp_x][i]==char(219))
			return 0;
	}
}
int right_shot_line(int comp_x,int comp_y,int user_y,char field[][31])
{
	comp_y++;
	for (int i=comp_y;i<user_y;i++)
	{
		if (field[comp_x][i]==char(219))
			return 0;
	}
}
int back_shot_line(int comp_x,int comp_y,int user_x,char field[][31])
{
	comp_x++;
	for (int i=comp_x;i<user_x;i++)
	{
		if (field[i][comp_y]==char(219))
			return 0;
	}
}
int main()
{
	int user_x=19,user_y=0,user_shot_index=1,user_bullet_x,user_bullet_y;
	int comp_x=0,comp_y=30,comp_shot_index=3,comp_bullet_x,comp_bullet_y;
	int abs_x,abs_y;
	int result_user=0,result_comp=0;
	char field [20][31];
	char action;
	game_info();
	srand(time(0));
	game_map(user_x,user_y,comp_x,comp_y,field);
	for(;;)
	{
		user_bullet_x=user_x;
	    user_bullet_y=user_y;
		comp_bullet_x=comp_x;
	    comp_bullet_y=comp_y;
		screen_refresh(field);
		cout<<"  Action : ";
		cin>>action;
		switch(action)
		{
		case 'i':
			{
			    if (field[user_x-1][user_y]==char(255))
	            {
					user_move_top(user_x,user_y,field);
				    user_x--;
		            user_shot_index=1;
	            }
			    else if (field[user_x-1][user_y]==char(15))
					user_top_mine(user_x,user_y,field);
			}
			break;
		case 'j':
			{
			    if (field[user_x][user_y-1]==char(255)&&user_y!=0)
	            {
					user_move_left(user_x,user_y,field);
				    user_y--;
		            user_shot_index=4;
	            }
				else if (field[user_x][user_y-1]==char(15))
					user_left_mine(user_x,user_y,field);
			}
			break;
		case 'l':
			{
			    if (field[user_x][user_y+1]==char(255)&&user_y+1!=31)
	            {
					user_move_right(user_x,user_y,field);
				    user_y++;
		            user_shot_index=2;
	            }
				else if (field[user_x][user_y+1]==char(15))
					user_right_mine(user_x,user_y,field);
			}
			break;
		case 'k':
			{
			    if (field[user_x+1][user_y]==char(255))
	            {
					user_move_back(user_x,user_y,field);
				    user_x++;
		            user_shot_index=3;
	            }
				else if (field[user_x+1][user_y]==char(15))
					user_back_mine(user_x,user_y,field);
			}
			break;
		case 's':
			{
				switch(user_shot_index)
				{
				case 1:
					{
						for (;;)
						{
							if (user_top_shot(user_bullet_x,user_bullet_y,field)==0)
								break;
							user_bullet_x=user_bullet_x-1;
							screen_refresh(field);
						}
					}
					break;
				case 2:
					{
						for (;;)
						{
							if (user_right_shot(user_bullet_x,user_bullet_y,field)==0)
								break;
							user_bullet_y=user_bullet_y+1;
							screen_refresh(field);
						}
					}
					break;
				case 3:
					{
						for (;;)
						{
							if (user_back_shot(user_bullet_x,user_bullet_y,field)==0)
								break;
							user_bullet_x=user_bullet_x+1;
							screen_refresh(field);
						}
					}
					break;
				case 4:
					{
						for (;;)
						{
							if (user_left_shot(user_bullet_x,user_bullet_y,field)==0)
								break;
							user_bullet_y=user_bullet_y-1;
							screen_refresh(field);
						}
					}
					break;
				}
			}
			break;
		case 'e':
			{
				game_info();
			}
			break;
		}
		result_user=0,result_comp=0;
		for (int i=0;i<20;i++)
			for (int j=0;j<31;j++)
			{
				if (field[i][j]==char(2))
					result_user++;
				else if (field[i][j]==char(1))
					result_comp++;
			}
		if (result_user==0)
		{
			screen_refresh(field);
			cout<<"  You lose!!!\n"<<endl;
			break;
		}
		else if (result_user==1&&result_comp==1)
			system("cls");
		else if (result_comp==0)
		{
			screen_refresh(field);
			cout<<"  You win!!!\n"<<endl;
			break;
		}
		abs_x=abs(user_x-comp_x);
		abs_y=abs((user_y-comp_y)/1.55);
		if (comp_y==user_y&&comp_x>user_x&&field[comp_x-1][comp_y]==char(255)&&field[comp_x-2][comp_y]==char(255)&&comp_x!=0&&top_shot_line(comp_x,comp_y,user_x,field)!=0)
		{
			comp_move_top(comp_x,comp_y,field);
			comp_x--;
			screen_refresh(field);
			for (;;)
			{
				if (comp_top_shot(comp_bullet_x,comp_bullet_y,field)==0)
					break;
				comp_bullet_x--;
				screen_refresh(field);
			}
		}
		else if (comp_x==user_x&&comp_y<user_y&&field[comp_x][comp_y+1]==char(255)&&field[comp_x][comp_y+2]==char(255)&&comp_y!=30&&right_shot_line(comp_x,comp_y,user_y,field)!=0)
		{
			comp_move_right(comp_x,comp_y,field);
			comp_y++;
			screen_refresh(field);
			for (;;)
			{
				if (comp_right_shot(comp_bullet_x,comp_bullet_y,field)==0)
					break;
				comp_bullet_y++;
				screen_refresh(field);
			}
		}
		else if (comp_x==user_x&&comp_y>user_y&&field[comp_x][comp_y-1]==char(255)&&field[comp_x][comp_y-2]==char(255)&&comp_y!=0&&left_shot_line(comp_x,comp_y,user_y,field)!=0)
		{
			comp_move_left(comp_x,comp_y,field);
			comp_y--;
			screen_refresh(field);
			for (;;)
			{
				if (comp_left_shot(comp_bullet_x,comp_bullet_y,field)==0)
					break;
				comp_bullet_y--;
				screen_refresh(field);
			}
		}
		else if (comp_y==user_y&&comp_x<user_x&&field[comp_x+1][comp_y]==char(255)&&field[comp_x+2][comp_y]==char(255)&&comp_x!=19&&back_shot_line(comp_x,comp_y,user_x,field)!=0)
		{
			comp_move_back(comp_x,comp_y,field);
			comp_x++;
			screen_refresh(field);
			for (;;)
			{
				if (comp_back_shot(comp_bullet_x,comp_bullet_y,field)==0)
					break;
				comp_bullet_x++;
				screen_refresh(field);
			}
		}
		else if (field[comp_x-1][comp_y]==char(255)&&user_x<comp_x&&comp_x!=0&&abs_x<abs_y)
		{
			comp_move_top(comp_x,comp_y,field);
			comp_x--;
	    }
		else if (field[comp_x-1][comp_y]==char(219)||field[comp_x-1][comp_y]==char(15)&&user_x<comp_x&&abs_x<abs_y)
		{
			if (field[comp_x][comp_y-1]==char(255)&&user_y<comp_y&&comp_y!=0)
			{
				comp_move_left(comp_x,comp_y,field);
				comp_y--;
			}
			else if (field[comp_x][comp_y+1]==char(255)&&user_y>comp_y&&comp_y!=30)
			{
				comp_move_right(comp_x,comp_y,field);
				comp_y++;
			}
			else if (field[comp_x][comp_y-1]==char(176)&&user_y<comp_y)
			{
				if (field[comp_x][comp_y+1]==char(255)&&field[comp_x][comp_y+2]==char(255)&&comp_y!=30)
				{
					comp_move_right(comp_x,comp_y,field);
					comp_y++;
					screen_refresh(field);
				    comp_move_right(comp_x,comp_y,field);
					comp_y++;
					screen_refresh(field);
					comp_move_left(comp_x,comp_y,field);
					comp_y--;
					screen_refresh(field);
					for (;;)
					{
						if (comp_left_shot(comp_bullet_x,comp_bullet_y,field)==0)
							break;
						comp_bullet_y--;
						screen_refresh(field);
					}
				}
			}
			else if (field[comp_x][comp_y+1]==char(176)&&user_y>comp_y)
			{
				if (field[comp_x][comp_y-1]==char(255)&&field[comp_x][comp_y-2]==char(255)&&comp_y!=0)
				{
					comp_move_left(comp_x,comp_y,field);
					comp_y--;
					screen_refresh(field);
					comp_move_left(comp_x,comp_y,field);
					comp_y--;
					screen_refresh(field);
					comp_move_right(comp_x,comp_y,field);
					comp_y++;
					screen_refresh(field);
					for (;;)
					{
						if (comp_right_shot(comp_bullet_x,comp_bullet_y,field)==0)
							break;
						comp_bullet_y++;
						screen_refresh(field);
					}
				}
			}
		}
		else if (field[comp_x-1][comp_y]==char(176)&&user_x<comp_x&&abs_x<abs_y)
		{
			if (field[comp_x+1][comp_y]==char(255)&&field[comp_x+2][comp_y]==char(255)&&comp_x!=19)
			{
				comp_move_back(comp_x,comp_y,field);
				comp_x++;
				screen_refresh(field);
				comp_move_back(comp_x,comp_y,field);
				comp_x++;
				screen_refresh(field);
				comp_move_top(comp_x,comp_y,field);
				comp_x--;
				screen_refresh(field);
				for (;;)
				{
					if (comp_top_shot(comp_bullet_x,comp_bullet_y,field)==0)
						break;
					comp_bullet_x--;
					screen_refresh(field);
			    }
			}
		}
		else if (field[comp_x+1][comp_y]==char(255)&&user_x>comp_x&&comp_x!=19&&abs_x<abs_y)
		{
			comp_move_back(comp_x,comp_y,field);
			comp_x++;
		}
		else if (field[comp_x+1][comp_y]==char(219)||field[comp_x+1][comp_y]==char(15)&&user_x>comp_x&&abs_x<abs_y)
		{
			if (field[comp_x][comp_y-1]==char(255)&&user_y<comp_y&&comp_y!=0)
			{
				comp_move_left(comp_x,comp_y,field);
				comp_y--;
			}
			else if (field[comp_x][comp_y+1]==char(255)&&user_y>comp_y&&comp_y!=30)
			{
				comp_move_right(comp_x,comp_y,field);
				comp_y++;
			}
			else if (field[comp_x][comp_y-1]==char(176)&&user_y<comp_y&&comp_y!=0)
			{
				if (field[comp_x][comp_y+1]==char(255)&&field[comp_x][comp_y+2]==char(255)&&comp_y!=30)
				{
					comp_move_right(comp_x,comp_y,field);
				    comp_y++;
				    screen_refresh(field);
					comp_move_right(comp_x,comp_y,field);
				    comp_y++;
				    screen_refresh(field);
					comp_move_left(comp_x,comp_y,field);
				    comp_y--;
				    screen_refresh(field);
					for (;;)
				    {
					    if (comp_left_shot(comp_bullet_x,comp_bullet_y,field)==0)
						    break;
					    comp_bullet_y--;
					    screen_refresh(field);
					}
				}
			}
		    else if (field[comp_x][comp_y+1]==char(176)&&user_y>comp_y&&comp_y!=30)
			{
				if (field[comp_x][comp_y-1]==char(255)&&field[comp_x][comp_y-2]==char(255)&&user_y!=0)
				{
					comp_move_left(comp_x,comp_y,field);
				    comp_y--;
				    screen_refresh(field);
					comp_move_left(comp_x,comp_y,field);
				    comp_y--;
				    screen_refresh(field);
					comp_move_right(comp_x,comp_y,field);
				    comp_y++;
				    screen_refresh(field);
					for (;;)
				    {
					    if (comp_right_shot(comp_bullet_x,comp_bullet_y,field)==0)
						    break;
					    comp_bullet_y++;
					    screen_refresh(field);
					}
				}
			}
		}
		else if (field[comp_x+1][comp_y]==char(176)&&user_x>comp_x&&abs_x<abs_y)
		{
			if (field[comp_x-1][comp_y]==char(255)&&field[comp_x-2][comp_y]==char(255)&&comp_x!=0)
			{
				comp_move_top(comp_x,comp_y,field);
				comp_x--;
				screen_refresh(field);
				comp_move_top(comp_x,comp_y,field);
				comp_x--;
				screen_refresh(field);
				comp_move_back(comp_x,comp_y,field);
				comp_x++;
				screen_refresh(field);
				for (;;)
			    {
				    if (comp_back_shot(comp_bullet_x,comp_bullet_y,field)==0)
					    break;
				    comp_bullet_x++;
				    screen_refresh(field);
				}
			}
		}
		else if (field[comp_x][comp_y-1]==char(255)&&user_y<comp_y&&comp_y!=0&&abs_y<abs_x)
		{
			comp_move_left(comp_x,comp_y,field);
			comp_y--;
		}
		else if (field[comp_x][comp_y-1]==char(219)||field[comp_x][comp_y-1]==char(15)&&user_y<comp_y&&abs_y<abs_x)
		{
			if (field[comp_x-1][comp_y]==char(255)&&user_x<comp_x&&comp_x!=0)
			{
				comp_move_top(comp_x,comp_y,field);
				comp_x--;
			}
			else if (field[comp_x+1][comp_y]==char(255)&&user_x>comp_x&&comp_x!=19)
			{
				comp_move_back(comp_x,comp_y,field);
				comp_x++;
			}
			else if (field[comp_x-1][comp_y]==char(176)&&user_x<comp_x)
			{
				if (field[comp_x+1][comp_y]==char(255)&&field[comp_x+2][comp_y]==char(255)&&comp_x!=19)
			    {
				    comp_move_back(comp_x,comp_y,field);
				    comp_x++;
					screen_refresh(field);
				    comp_move_back(comp_x,comp_y,field);
				    comp_x++;
					screen_refresh(field);
				    comp_move_top(comp_x,comp_y,field);
				    comp_x--;
					screen_refresh(field);
				    for (;;)
					{
						if (comp_top_shot(comp_bullet_x,comp_bullet_y,field)==0)
							break;
						comp_bullet_x--;
						screen_refresh(field);
					}
				}
			}
			else if (field[comp_x+1][comp_y]==char(176)&&user_x>comp_x)
			{
				if (field[comp_x-1][comp_y]==char(255)&&field[comp_x-2][comp_y]==char(255)&&comp_x!=0)
				{
					comp_move_top(comp_x,comp_y,field);
				    comp_x--;
					screen_refresh(field);
				    comp_move_top(comp_x,comp_y,field);
				    comp_x--;
					screen_refresh(field);
				    comp_move_back(comp_x,comp_y,field);
				    comp_x++;
					screen_refresh(field);
				    for (;;)
					{
						if (comp_back_shot(comp_bullet_x,comp_bullet_y,field)==0)
							break;
						comp_bullet_x++;
						screen_refresh(field);
					}
				}
			}
		}
		else if (field[comp_x][comp_y-1]==char(176)&&user_x>comp_x&&abs_y<abs_x)
		{
			if (field[comp_x][comp_y+1]==char(255)&&field[comp_x][comp_y+2]==char(255)&&comp_y!=30)
			{
				comp_move_right(comp_x,comp_y,field);
				comp_y++;
				screen_refresh(field);
				comp_move_right(comp_x,comp_y,field);
				comp_y++;
				screen_refresh(field);
				comp_move_left(comp_x,comp_y,field);
				comp_y--;
				screen_refresh(field);
				for (;;)
				{
					if (comp_left_shot(comp_bullet_x,comp_bullet_y,field)==0)
						break;
					comp_bullet_y--;
					screen_refresh(field);
				}
			}
		}
		else if (field[comp_x][comp_y+1]==char(255)&&user_y>comp_y&&comp_y!=30&&abs_y<abs_x)
		{
			comp_move_right(comp_x,comp_y,field);
			comp_y++;
		}
		else if (field[comp_x][comp_y+1]==char(219)||field[comp_x][comp_y+1]==char(15)&&user_y>comp_y&&abs_y<abs_x)
		{
			if (field[comp_x-1][comp_y]==char(255)&&user_x<comp_x&&comp_x!=0)
			{
				comp_move_top(comp_x,comp_y,field);
				comp_x--;
			}
			else if (field[comp_x+1][comp_y]==char(255)&&user_x>comp_x&&comp_x!=19)
			{
				comp_move_back(comp_x,comp_y,field);
				comp_x++;
			}
			else if (field[comp_x-1][comp_y]==char(176)&&user_x<comp_x&&comp_x!=0)
			{
				if (field[comp_x+1][comp_y]==char(255)&&field[comp_x+2][comp_y]==char(255)&&comp_x!=19)
				{
					comp_move_back(comp_x,comp_y,field);
					comp_x++;
					screen_refresh(field);
					comp_move_back(comp_x,comp_y,field);
					comp_x++;
					screen_refresh(field);
					comp_move_top(comp_x,comp_y,field);
					comp_x--;
					screen_refresh(field);
					for (;;)
					{
						if (comp_top_shot(comp_bullet_x,comp_bullet_y,field)==0)
							break;
						comp_bullet_x--;
						screen_refresh(field);
					}
				}
			}
			else if (field[comp_x+1][comp_y]==char(176)&&user_x>comp_x&&comp_x!=19)
			{
				if (field[comp_x-1][comp_y]==char(255)&&field[comp_x-2][comp_y]==char(255)&&comp_x!=0)
				{
					comp_move_top(comp_x,comp_y,field);
					comp_x--;
					screen_refresh(field);
					comp_move_top(comp_x,comp_y,field);
					comp_x--;
					screen_refresh(field);
					comp_move_back(comp_x,comp_y,field);
					comp_x++;
					screen_refresh(field);
					for (;;)
					{
						if (comp_back_shot(comp_bullet_x,comp_bullet_y,field)==0)
							break;
						comp_bullet_x++;
						screen_refresh(field);
					}
				}
			}
		}
		else if (field[comp_x][comp_y+1]==char(176)&&user_y>comp_y)
		{
			if (field[comp_x][comp_y-1]==char(255)&&field[comp_x][comp_y-2]==char(255)&&comp_y!=0)
			{
				comp_move_left(comp_x,comp_y,field);
				comp_y--;
				screen_refresh(field);
				comp_move_left(comp_x,comp_y,field);
				comp_y--;
				screen_refresh(field);
				comp_move_right(comp_x,comp_y,field);
				comp_y++;
				screen_refresh(field);
				for (;;)
				{
					if (comp_right_shot(comp_bullet_x,comp_bullet_y,field)==0)
						break;
					comp_bullet_y++;
					screen_refresh(field);
				}
			}
		}
		result_user=0,result_comp=0;
		for (int i=0;i<20;i++)
		{
			for (int j=0;j<31;j++)
			{
				if (field[i][j]==char(2))
					result_user++;
				else if (field[i][j]==char(1))
					result_comp++;
			}
		}
		if (result_user==0)
		{
			screen_refresh(field);
			cout<<"  You lose!!!\n"<<endl;
			break;
		}
		else if (result_user==1&&result_comp==1)
			system("cls");
		else if (result_comp==0)
		{
			screen_refresh(field);
			cout<<"  You win!!!\n"<<endl;
			break;
		}
	}
	return 0;
}