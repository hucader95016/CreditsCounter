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
                cout << "尚未建立課程清單\n" ;
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
    cout << "\n請選擇課程類別\n1.系必修 2.通識基礎 3.通識延伸 4.選修(含系選和自由) 5.基本知能 :" ;
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
        cout << "請選擇分類\n" ;
        cout << "1.宗哲 2.人哲 3.公民 4.歷史 5.文學 6.其他 :" ;
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
        cout << "請選擇分類\n" ;
        cout << "1.天 2.人 3.物 4.我 :" ;
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
        cout << "請選擇分類\n" ;
        cout << "1.系選修 2.自由選修 :" ;
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
        cout << "請選擇分類\n" ;
        cout << "1.大一英文 2.大一英聽 3.大二英文 4.還服 5.體育 :" ;
        cin >> typeNum ;
        walk -> next = new Type ;
        walk = walk -> next ;
        walk -> num = typeNum - 1 ;
        walk -> next = NULL ;
    } // else if

    else
        cout << "Input Error\n" ;

    cout << "請輸入課程名稱:" ;
    cin >> temp.name ;
    cout << "請輸入學分數:" ;
    cin >> temp.credit ;

    return temp ;
} // ReadInput()

