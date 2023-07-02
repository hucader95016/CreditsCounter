# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <iostream>
# include <vector>
# include "DataStruct.cpp"

using namespace std ;

typedef char Str[50] ;

bool IsCmd( Str cmd ) ;
Data ReadInput() ;

int main() {
    DataVector dataVector ;
    Str cmd ;
    string typeName, courseName ;
    int credit ;
    Data temp ;

    cout << "Please Enter A Command\n" ;
    cout << "Add Course[a]\nWatch Your Credit[s]\nQuit[q]\n:" ;
    cin >> cmd ;
    while ( !IsCmd( cmd ) ) {
        cout << "Illegally Command!\n" ;
        cout << "Please Enter Your Command Again:" ;
        cin >> cmd ;
    } // while

    dataVector.Read() ;
    while ( strcmp( cmd, "q" ) != 0 ) {
        if ( strcmp( cmd, "a" ) == 0 ) {
            while ( strcmp( cmd, "q" ) != 0 ) {
                temp = ReadInput() ;
                dataVector.Add( temp ) ;
                cout << "\nAdd Successful" ;
                cout << "\nKeep Adding 'a' or Enter 'q' To Quit:" ;
                cin >> cmd ;
            } // while()

            dataVector.Sort() ; // bug,empty vector
            dataVector.Update() ;
            dataVector.Write_credit() ;
            dataVector.Write_course() ;
            system( "cls" ) ;
        } // if

        else { // show
            if ( dataVector.IsEmpty() )
                cout << "�|���إ߽ҵ{�M��\n" ;
            else {
                dataVector.Debug() ;
                dataVector.Update() ;
                dataVector.Write_credit() ;
                dataVector.Write_course() ;
                dataVector.Show() ;
            } // else
        } // show

        cout << "\nPlease Enter A Command\n" ;
        cout << "Add Course[a]\nWatch Your Credit[s]\nQuit[q]\n:" ;
        cin >> cmd ;
        while ( !IsCmd( cmd ) ) {
            cout << "Illegally Command!\n" ;
            cout << "Please Enter Your Command Again:" ;
            cin >> cmd ;
        } // while
    } // while
} // main()

bool IsCmd( Str cmd ) {
    if ( strcmp( cmd, "a" ) == 0 )
        return true ;
    else if ( strcmp( cmd, "s" ) == 0 )
        return true ;
    else if ( strcmp( cmd, "q" ) == 0 )
        return true ;

    return false ;
} // IsCmd()

Data ReadInput() {
    Data temp ;
    int typeNum ;
    cout << "\n�п�ܽҵ{���O\n1.�t���� 2.�q�Ѱ�¦ 3.�q�ѩ��� 4.���(�t�t��M�ۥ�) 5.�򥻪��� :" ;
    cin >> typeNum ;
    if ( typeNum == 1 ) {
        temp.typeHead = new Type ;
        temp.typeHead -> next = NULL ;
        temp.typeHead -> num = typeNum - 1 ;
    } // if

    else if ( typeNum == 2 ) {
        Type *walk ;
        temp.typeHead = new Type ;
        walk = temp.typeHead ;
        walk -> num = typeNum - 1 ;
        walk -> next = NULL ;
        cout << "�п�ܤ���\n" ;
        cout << "1.�v�� 2.�H�� 3.���� 4.���v 5.��� 6.��L :" ;
        cin >> typeNum ;
        walk -> next = new Type ;
        walk = walk -> next ;
        walk -> num = typeNum - 1 ;
        walk -> next = NULL ;
    } // else if

    else if ( typeNum == 3 ) {
        Type *walk ;
        temp.typeHead = new Type ;
        walk = temp.typeHead ;
        walk -> num = typeNum - 1 ;
        walk -> next = NULL ;
        cout << "�п�ܤ���\n" ;
        cout << "1.�� 2.�H 3.�� 4.�� :" ;
        cin >> typeNum ;
        walk -> next = new Type ;
        walk = walk -> next ;
        walk -> num = typeNum - 1 ;
        walk -> next = NULL ;
    } // else if

    else if ( typeNum == 4 ) {
        Type *walk ;
        temp.typeHead = new Type ;
        walk = temp.typeHead ;
        walk -> num = typeNum - 1 ;
        walk -> next = NULL ;
        cout << "�п�ܤ���\n" ;
        cout << "1.�t��� 2.�ۥѿ�� :" ;
        cin >> typeNum ;
        walk -> next = new Type ;
        walk = walk -> next ;
        walk -> num = typeNum - 1 ;
        walk -> next = NULL ;
    } // else if

    else if ( typeNum == 5 ) {
        Type *walk ;
        temp.typeHead = new Type ;
        walk = temp.typeHead ;
        walk -> num = typeNum - 1 ;
        walk -> next = NULL ;
        cout << "�п�ܤ���\n" ;
        cout << "1.�j�@�^�� 2.�j�@�^ť 3.�j�G�^�� 4.�٪A 5.��| :" ;
        cin >> typeNum ;
        walk -> next = new Type ;
        walk = walk -> next ;
        walk -> num = typeNum - 1 ;
        walk -> next = NULL ;
    } // else if

    else
        cout << "Input Error\n" ;

    cout << "�п�J�ҵ{�W��:" ;
    cin >> temp.name ;
    cout << "�п�J�Ǥ���:" ;
    cin >> temp.credit ;

    return temp ;
} // ReadInput()

