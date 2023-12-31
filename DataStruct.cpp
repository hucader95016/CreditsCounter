# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <vector>
# include <iostream>
# include <fstream>

# define GRADUATIONSUM 128
# define DEPARTMENTNEED 80
# define CHOISECREDIT 14
# define COMMENSENCE 14
# define COMMENSENCEPLUS 14
# define BASEMENT 6

static int sGraduation = 0 ;
static int sDepartmentNeed = 0 ;
static int sChoiseCredit = 0 ;
static int sCommence = 0 ;
static int sCommencePlus = 0 ;
static int sBasement = 0 ;


using namespace std ;
typedef char c_str[256] ;

struct Type {
	int num ;
	Type *next ;
} ; // Type()

typedef Type *TypePtr ;

struct Data {
	TypePtr typeHead ;
	string name ;
	int credit ;
	// string semester ;
} ; // Data()

class DataVector {
    std :: vector<Data> datas ;

    public :
        void Read() {
            Data temp ;
            int pre, pos, fNo ;
            fstream inputFile ;
            string fileName = "Passed Courses" ;
            c_str inputLine ;
            inputFile.open( fileName.c_str(), fstream :: in ) ;
            if ( inputFile.is_open() ) {
                while ( inputFile.getline( inputLine, 256, '\n' ) && strcmp( inputLine, "\n" ) != 0 ) {
                    temp = Data() ;
                    std :: string buf, cut ;
                    buf.assign( inputLine ) ;
                    fNo = 1 ;
                    pre = 0 ;
                    pos = buf.find_first_of( ' ', pre ) ;
                    while ( pos > 0 && fNo < 4 ) {
                        cut = buf.substr( pre, pos-pre ) ;
                        cout << cut << endl ;
                        if ( fNo == 1 ) {
                            if ( cut == "系必修" ) {
                                temp.typeHead = new Type ;
                                temp.typeHead -> num = 0 ;
                                temp.typeHead -> next = NULL ;
                            } // if

                            else if ( cut == "通識基礎" ) {
                                temp.typeHead = new Type ;
                                TypePtr walk = temp.typeHead ;
                                walk -> num = 1 ;
                                pre = pos + 1 ;
                                pos = buf.find_first_of( ' ', pre ) ;
                                cut = buf.substr( pre, pos-pre ) ;
                                if ( cut == "宗哲" ) {
                                    walk -> next = new Type ;
                                    walk = walk -> next ;
                                    walk -> num = 0 ;
                                    walk -> next = NULL ;
                                } // if

                                else if ( cut == "人哲" ) {
                                    walk -> next = new Type ;
                                    walk = walk -> next ;
                                    walk -> num = 1 ;
                                    walk -> next = NULL ;
                                } // else if

                                else if ( cut == "公民" ) {
                                    walk -> next = new Type ;
                                    walk = walk -> next ;
                                    walk -> num = 2 ;
                                    walk -> next = NULL ;
                                } // else if

                                else if ( cut == "歷史" ) {
                                    walk -> next = new Type ;
                                    walk = walk -> next ;
                                    walk -> num = 3 ;
                                    walk -> next = NULL ;
                                } // else if

                                else if ( cut == "文學" ) {
                                    walk -> next = new Type ;
                                    walk = walk -> next ;
                                    walk -> num = 4 ;
                                    walk -> next = NULL ;
                                } // else if

                                else { // 其他
                                    walk -> next = new Type ;
                                    walk = walk -> next ;
                                    walk -> num = 5 ;
                                    walk -> next = NULL ;
                                } // else
                            } // else if

                            else if ( cut == "通識延伸" ) {
                                temp.typeHead = new Type ;
                                TypePtr walk = temp.typeHead ;
                                walk -> num = 2 ;
                                pre = pos + 1 ;
                                pos = buf.find_first_of( ' ', pre ) ;
                                cut = buf.substr( pre, pos-pre ) ;
                                if ( cut == "天" ) {
                                    walk -> next = new Type ;
                                    walk = walk -> next ;
                                    walk -> num = 0 ;
                                    walk -> next = NULL ;
                                } // if

                                else if ( cut == "人" ) {
                                    walk -> next = new Type ;
                                    walk = walk -> next ;
                                    walk -> num = 1 ;
                                    walk -> next = NULL ;
                                } // else if

                                else if ( cut == "物" ) {
                                    walk -> next = new Type ;
                                    walk = walk -> next ;
                                    walk -> num = 2 ;
                                    walk -> next = NULL ;
                                } // else if

                                else if ( cut == "我" ) {
                                    walk -> next = new Type ;
                                    walk = walk -> next ;
                                    walk -> num = 3 ;
                                    walk -> next = NULL ;
                                } // else if
                            } // else if

                            else if ( cut == "選修" ) {
                                temp.typeHead = new Type ;
                                TypePtr walk = temp.typeHead ;
                                walk -> num = 2 ;
                                pre = pos + 1 ;
                                pos = buf.find_first_of( ' ', pre ) ;
                                cut = buf.substr( pre, pos-pre ) ;
                                if ( cut == "自由" ) {
                                    walk -> next = new Type ;
                                    walk = walk -> next ;
                                    walk -> num = 0 ;
                                    walk -> next = NULL ;
                                } // if

                                else if ( cut == "系" ) {
                                    walk -> next = new Type ;
                                    walk = walk -> next ;
                                    walk -> num = 1 ;
                                    walk -> next = NULL ;
                                } // else if
                            } // else if

                            else { // 基本知能
                                temp.typeHead = new Type ;
                                TypePtr walk = temp.typeHead ;
                                walk -> num = 2 ;
                                pre = pos + 1 ;
                                pos = buf.find_first_of( ' ', pre ) ;
                                cut = buf.substr( pre, pos-pre ) ;
                                if ( cut == "大一英文" ) {
                                    walk -> next = new Type ;
                                    walk = walk -> next ;
                                    walk -> num = 0 ;
                                    walk -> next = NULL ;
                                } // if

                                else if ( cut == "大一英聽" ) {
                                    walk -> next = new Type ;
                                    walk = walk -> next ;
                                    walk -> num = 1 ;
                                    walk -> next = NULL ;
                                } // else if

                                else if ( cut == "大二英文" ) {
                                    walk -> next = new Type ;
                                    walk = walk -> next ;
                                    walk -> num = 2 ;
                                    walk -> next = NULL ;
                                } // else if

                                else if ( cut == "還服" ) {
                                    walk -> next = new Type ;
                                    walk = walk -> next ;
                                    walk -> num = 3 ;
                                    walk -> next = NULL ;
                                } // else if

                                else { // 體育
                                    walk -> next = new Type ;
                                    walk = walk -> next ;
                                    walk -> num = 4 ;
                                    walk -> next = NULL ;
                                } // else
                            } // else
                        } // if

                        else if ( fNo == 2 ) {
                            temp.name = cut ;
                        } // else if

                        else if ( fNo == 3 ) {
                            temp.credit = atoi( cut.c_str() ) ;
                        } // else if

                        fNo++ ;
                        pre = pos + 1 ;
                        pos = buf.find_first_of( ' ', pre ) ;
                    } // while

                    Add( temp ) ;
                } // while()
            } // if
        } // Read

        void Add( Data temp ) {
            datas.push_back( temp ) ;
        } // Add

        void Sort() {
            int i = 0 ;
            int minmun ;
            int index ;
            for ( i = 0 ; i < datas.size() ; i++ ) {
                minmun = datas[i].typeHead -> num ;
                index = i ;
                for ( int j = i ; j < datas.size() ; j++ ) {
                    if ( datas[j].typeHead -> num < minmun ) {
                        minmun = datas[j].typeHead -> num ;
                        index = j ;
                    } // if
                } // for

                if ( index != i )
                    std :: swap( datas[i], datas[index] ) ;
            } // for
        } // Sort()

        void Write_credit() { // 已修學分數及距離畢業所需學分數
            string fileName = "學分數.txt" ;
            fstream outfile ;
            bool allCom = false, com0 = false, com1 = false, com2 = false ; // 宗 人 公
            bool com3 = false, com4 = false, com5 = false ; // 史 文學 其他
            int sora = 0 ;
            int hito = 0 ;
            int mono = 0 ;
            int boku = 0 ;
            int english1 = 0, english2 = 0, listening = 0 ;
            int serve = 0, PE = 0 ; // serve need 2,PE need 4
            for ( int i = 0 ; i < datas.size() ; i++ ) {
                if ( datas[i].typeHead -> num == 1 ) {
                    TypePtr walk = datas[i].typeHead -> next ;

                    if ( walk -> num == 0 )
                        com0 = true ;
                    else if ( walk -> num == 1 )
                        com1 = true ;
                    else if ( walk -> num == 2 )
                        com2 = true ;
                    else if ( walk -> num == 3 )
                        com3 = true ;
                    else if ( walk -> num == 4 )
                        com4 = true ;
                    else if ( walk -> num == 5 )
                        com5 = true ;
                } // else if

                else if ( datas[i].typeHead -> num == 2 ) {
                    TypePtr walk = datas[i].typeHead -> next ;
                    if ( walk -> num == 0 )
                        sora++ ;
                    else if ( walk -> num == 1 )
                        hito++ ;
                    else if ( walk -> num == 2 )
                        mono++ ;
                    else if ( walk -> num == 3 )
                        boku++ ;
                } // else if

                else if ( datas[i].typeHead -> num == 4 ) {
                    TypePtr walk = datas[i].typeHead -> next ;
                    if ( walk -> num == 0 )
                        english1++ ;
                    else if ( walk -> num == 1 )
                        listening++ ;
                    else if ( walk -> num == 2 )
                        english2++ ;
                    else if ( walk -> num == 3 )
                        serve++ ;
                    else if ( walk -> num == 4 )
                        PE++ ;
                } // else if
            } // for

            if ( com0 && com1 && com2 && com3 && com4 && com5 )
                allCom = true ;

            outfile.open( fileName.c_str(), fstream :: out | ios :: trunc ) ;
            outfile << "距離畢業所需學分:" << GRADUATIONSUM << "/" << sGraduation << endl ;
            outfile << "系上必修學分:" << DEPARTMENTNEED << "/" << sDepartmentNeed << endl ;
            outfile << "通識基礎學分:" << COMMENSENCE << "/" << sCommence << endl ;
            if ( sCommence < 14 ) {
                if ( allCom )
                    outfile << "    文學少修一堂!" << endl ;
                else {
                    if ( !com0 )
                        outfile << "    宗哲尚未修畢!" << endl ;
                    if ( !com1 )
                        outfile << "    人哲尚未修畢!" << endl ;
                    if ( !com2 )
                        outfile << "    公民尚未修畢!" << endl ;
                    if ( !com3 )
                        outfile << "    歷史尚未修畢!" << endl ;
                    if ( !com4 )
                        outfile << "    文學兩堂都尚未修畢!" << endl ;
                    if ( !com5 )
                        outfile << "    其他尚未修畢!" << endl ;
                } // else
            } // if

            outfile << "通識延伸學分:" << COMMENSENCEPLUS << "/" << sCommencePlus << endl ;
            outfile << "    天學修畢" << sora << "堂\n" ;
            outfile << "    人學修畢" << hito << "堂\n" ;
            outfile << "    物學修畢" << mono << "堂\n" ;
            outfile << "    我學修畢" << boku << "堂\n" ;
            outfile << "選修學分:" << CHOISECREDIT << "/" << sChoiseCredit << endl ;
            outfile << "基本知能學分:" << BASEMENT << "/" << sBasement << endl ;
            if ( english1 == 0 )
                outfile << "    大一英文尚差兩堂!\n" ;
            else if ( english1 == 1 )
                outfile << "    大一英文尚差一堂!\n" ;

            if ( listening == 0 )
                outfile << "    大一英聽尚差兩堂!\n" ;
            else if ( listening == 1 )
                outfile << "    大一英聽尚差兩堂!\n" ;

            if ( english2 == 0 )
                outfile << "    大二英文尚差兩堂!\n" ;
            else if ( english2 == 1 )
                outfile << "    大二英文尚差一堂!\n" ;

            if ( serve == 0 )
                outfile << "    還服尚差兩堂!\n" ;
            else if ( serve == 1 )
                outfile << "    還服尚差一堂!\n" ;

            if ( PE < 6 )
                outfile << "    體育尚差" << 6-PE << "堂!\n" ;

            outfile.close() ;
        } // Write_credit()

        void Write_course() { // 已修習課程
            fstream outfile ;
            string fileName = "Passed Courses.txt" ;
            outfile.open( fileName.c_str(), fstream :: out | ios :: trunc ) ;
            if ( !outfile.is_open() )
                cout << "fuck" ;

            for ( int i = 0 ; i < datas.size() ; i++ ) {
                if ( datas[i].typeHead -> num == 0 )
                    outfile << "系必修" ;

                else if ( datas[i].typeHead -> num == 1 ) {
                    outfile << "通識基礎 " ;
                    TypePtr walk = datas[i].typeHead -> next ;
                    if ( walk -> num == 0 )
                        outfile << "宗哲" ;
                    else if ( walk -> num == 1 )
                        outfile << "人哲" ;
                    else if ( walk -> num == 2 )
                        outfile << "公民" ;
                    else if ( walk -> num == 3 )
                        outfile << "歷史" ;
                    else if ( walk -> num == 4 )
                        outfile << "文學" ;
                    else if ( walk -> num == 5 )
                        outfile << "其他" ;
                } // else if

                else if ( datas[i].typeHead -> num == 2 ) {
                    outfile << "通識延伸 " ;
                    TypePtr walk = datas[i].typeHead -> next ;
                    if ( walk -> num == 0 )
                        outfile << "天" ;
                    else if ( walk -> num == 1 )
                        outfile << "人" ;
                    else if ( walk -> num == 2 )
                        outfile << "物" ;
                    else if ( walk -> num == 3 )
                        outfile << "我" ;
                } // else if

                else if ( datas[i].typeHead -> num == 3 ) {
                    outfile << "選修 " ;
                    TypePtr walk = datas[i].typeHead -> next ;
                    if ( walk -> num == 0 )
                        outfile << "自由" ;
                    else if ( walk -> num == 1 )
                        outfile << "系" ;
                } // else if

                else if ( datas[i].typeHead -> num == 4 ) {
                    outfile << "基本知能 " ;
                    TypePtr walk = datas[i].typeHead -> next ;
                    if ( walk -> num == 0 )
                        outfile << "大一英文" ;
                    else if ( walk -> num == 1 )
                        outfile << "大一英聽" ;
                    else if ( walk -> num == 2 )
                        outfile << "大二英文" ;
                    else if ( walk -> num == 3 )
                        outfile << "還服" ;
                    else if ( walk -> num == 4 )
                        outfile << "體育" ;
                } // else if

                outfile << " " << datas[i].name ;
                outfile << " " << datas[i].credit << " " << endl ;
            } // for

            outfile.close() ;
        } // Write_course()

        void Update() {
            sGraduation = 0 ;
            sDepartmentNeed = 0 ;
            sChoiseCredit = 0 ;
            sCommence = 0 ;
            sCommencePlus = 0 ;
            sBasement = 0 ;

            for ( int i = 0 ; i < datas.size() ; i++ ) {
                if ( datas[i].typeHead -> num == 0 )
                   sDepartmentNeed += datas[i].credit ;

                else if ( datas[i].typeHead -> num == 1 ) {
                    sCommence += datas[i].credit ;
                } // else if

                else if ( datas[i].typeHead -> num == 2 ) {
                    sCommencePlus += datas[i].credit ;
                } // else if

                else if ( datas[i].typeHead -> num == 3 ) {
                    sChoiseCredit += datas[i].credit ;
                } // else if

                else if ( datas[i].typeHead -> num == 4 ) {
                    sBasement += datas[i].credit ;
                } // else if

                sGraduation += datas[i].credit ;
            } // for
        } // Update()

        void Show() {
            system( "cls" ) ;
            cout << "距離畢業所需學分:" << GRADUATIONSUM << "/" << sGraduation << endl ;
            cout << "系上必修學分:" << DEPARTMENTNEED << "/" << sDepartmentNeed << endl ;
            cout << "通識基礎學分:" << COMMENSENCE << "/" << sCommence << endl ;
            cout << "通識延伸學分:" << COMMENSENCEPLUS << "/" << sCommencePlus << endl ;
            cout << "選修學分:" << CHOISECREDIT << "/" << sChoiseCredit << endl ;
            cout << "基本知能學分:" << BASEMENT << "/" << sBasement << endl ;
        } // Show()

        bool IsEmpty() {
            return datas.empty() ;
        } // IsEmpty()

        void Debug() {
            cout << datas.size() << endl ;
            //cout << datas[1].typeHead -> num << " " << datas[1].name << " " << datas[1].credit << endl ;
        } // Debug()
} ; // class DataVector


