#include<bits/stdc++.h>
using namespace std;
char grid[10][10];
void setVertical(bool arr[],int r, int c,string str)
// {	int n=r+str.size();
 	int j=0; 
    for(int i=r;i<10;i++)
    {
        if(grid[i][c]=='-')
        {
            arr[j]=1;
            grid[i][c]=str[j];
        } else {
            arr[j] = 0;
        }
        j++;
    }
}
void setHorizontal(bool arr[],int r, int c,string str)
{	int n=str.size();
 	int j=0; 
    for(int i=c;i<10;i++)
    {
        if(grid[r][i]=='-')
        {
            arr[j]=1;
            grid[r][i]=str[j];
        } else {
            arr[j] = 0;
        }
        j++;
    }
}
void resetVertical(bool arr[],int r, int c,string str)
{	int n=str.size();
 	int j=0; 
    for(int i=r;i<10;i++)
    {
        if(arr[j])   
        {
            grid[i][c]='-';
        }
        j++;
    }
}
void resetHorizontal(bool arr[],int r, int c,string str)
{	int n=str.size();
 	int j=0; 
    for(int i=c;i<10;i++)
    {
        if(arr[j])   
        {
            grid[r][i]='-';
        }
        j++;
    }
}
bool isValidVertical(int r , int c, string str){
    int n=str.size();
    int count=0;
    int j=0;
    for(int i=r;i<10;i++){
        if(grid[i][c]=='+')
            break;
        if(grid[i][c]=='-' or grid[i][c]==str[j])
            count++;
        j++;
        if(count==str.size())
        	return true;
    }
    
    return false;
}
bool isValidHorizontal(int r , int c, string str){
    int n=str.size();
    int count=0;
    int j=0;
    for(int i=c;i<10;i++){
        if(grid[r][i]=='+')
            break;
        if(grid[r][i]=='-' or grid[r][i]==str[j])
            count++;
        j++;
        if(count==str.size())
        	return true;
    }
    
    return false;
}
bool solve(vector<string> words,int index){
    if(words.size()==index)
        return true;

    for(int r=0;r<10;r++){
        for(int c=0;c<10;c++){
            if(grid[r][c]=='-' or grid[r][c]==words[index][0])
            {
                string s=words[index];
                if(isValidVertical(r,c,words[index]))
                {
                    bool arr[s.size()];
                    setVertical(arr,r,c,words[index]);
				    if(solve(words,index+1))
                        return true;
                    else
                    resetVertical(arr,r,c,words[index]);
                }
                if(isValidHorizontal(r,c,words[index]))
                {
                    bool arr[s.size()];
                    setHorizontal(arr,r,c,words[index]);
 
                   	if(solve(words,index+1))
                        return true;
                    else
                    resetHorizontal(arr,r,c,words[index]);
                }
                
            }
        }
    }
                  
     return false;
}
int main(){
    
    // write your code here
    
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++)
            cin>>grid[i][j];
    }
    
    vector<string> words;
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        string temp="";
        while(i<s.length() && s[i]!=';')
        {
            temp+=s[i];
            i++;
        }
        if(temp.length())
            words.push_back(temp);
    }

     bool check = solve(words,0);
     // if(!check) return 0;
    
     for(int i=0;i<10;i++){
        for(int j=0;j<10;j++)
            cout<<grid[i][j];
         cout<<endl;
    }
    return 0;
}
