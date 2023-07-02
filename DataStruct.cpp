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
                            if ( cut == "�t����" ) {
                                temp.typeHead = new Type ;
                                temp.typeHead -> num = 0 ;
                                temp.typeHead -> next = NULL ;
                            } // if

                            else if ( cut == "�q�Ѱ�¦" ) {
                                temp.typeHead = new Type ;
                                TypePtr walk = temp.typeHead ;
                                walk -> num = 1 ;
                                pre = pos + 1 ;
                                pos = buf.find_first_of( ' ', pre ) ;
                                cut = buf.substr( pre, pos-pre ) ;
                                if ( cut == "�v��" ) {
                                    walk -> next = new Type ;
                                    walk = walk -> next ;
                                    walk -> num = 0 ;
                                    walk -> next = NULL ;
                                } // if

                                else if ( cut == "�H��" ) {
                                    walk -> next = new Type ;
                                    walk = walk -> next ;
                                    walk -> num = 1 ;
                                    walk -> next = NULL ;
                                } // else if

                                else if ( cut == "����" ) {
                                    walk -> next = new Type ;
                                    walk = walk -> next ;
                                    walk -> num = 2 ;
                                    walk -> next = NULL ;
                                } // else if

                                else if ( cut == "���v" ) {
                                    walk -> next = new Type ;
                                    walk = walk -> next ;
                                    walk -> num = 3 ;
                                    walk -> next = NULL ;
                                } // else if

                                else if ( cut == "���" ) {
                                    walk -> next = new Type ;
                                    walk = walk -> next ;
                                    walk -> num = 4 ;
                                    walk -> next = NULL ;
                                } // else if

                                else { // ��L
                                    walk -> next = new Type ;
                                    walk = walk -> next ;
                                    walk -> num = 5 ;
                                    walk -> next = NULL ;
                                } // else
                            } // else if

                            else if ( cut == "�q�ѩ���" ) {
                                temp.typeHead = new Type ;
                                TypePtr walk = temp.typeHead ;
                                walk -> num = 2 ;
                                pre = pos + 1 ;
                                pos = buf.find_first_of( ' ', pre ) ;
                                cut = buf.substr( pre, pos-pre ) ;
                                if ( cut == "��" ) {
                                    walk -> next = new Type ;
                                    walk = walk -> next ;
                                    walk -> num = 0 ;
                                    walk -> next = NULL ;
                                } // if

                                else if ( cut == "�H" ) {
                                    walk -> next = new Type ;
                                    walk = walk -> next ;
                                    walk -> num = 1 ;
                                    walk -> next = NULL ;
                                } // else if

                                else if ( cut == "��" ) {
                                    walk -> next = new Type ;
                                    walk = walk -> next ;
                                    walk -> num = 2 ;
                                    walk -> next = NULL ;
                                } // else if

                                else if ( cut == "��" ) {
                                    walk -> next = new Type ;
                                    walk = walk -> next ;
                                    walk -> num = 3 ;
                                    walk -> next = NULL ;
                                } // else if
                            } // else if

                            else if ( cut == "���" ) {
                                temp.typeHead = new Type ;
                                TypePtr walk = temp.typeHead ;
                                walk -> num = 2 ;
                                pre = pos + 1 ;
                                pos = buf.find_first_of( ' ', pre ) ;
                                cut = buf.substr( pre, pos-pre ) ;
                                if ( cut == "�ۥ�" ) {
                                    walk -> next = new Type ;
                                    walk = walk -> next ;
                                    walk -> num = 0 ;
                                    walk -> next = NULL ;
                                } // if

                                else if ( cut == "�t" ) {
                                    walk -> next = new Type ;
                                    walk = walk -> next ;
                                    walk -> num = 1 ;
                                    walk -> next = NULL ;
                                } // else if
                            } // else if

                            else { // �򥻪���
                                temp.typeHead = new Type ;
                                TypePtr walk = temp.typeHead ;
                                walk -> num = 2 ;
                                pre = pos + 1 ;
                                pos = buf.find_first_of( ' ', pre ) ;
                                cut = buf.substr( pre, pos-pre ) ;
                                if ( cut == "�j�@�^��" ) {
                                    walk -> next = new Type ;
                                    walk = walk -> next ;
                                    walk -> num = 0 ;
                                    walk -> next = NULL ;
                                } // if

                                else if ( cut == "�j�@�^ť" ) {
                                    walk -> next = new Type ;
                                    walk = walk -> next ;
                                    walk -> num = 1 ;
                                    walk -> next = NULL ;
                                } // else if

                                else if ( cut == "�j�G�^��" ) {
                                    walk -> next = new Type ;
                                    walk = walk -> next ;
                                    walk -> num = 2 ;
                                    walk -> next = NULL ;
                                } // else if

                                else if ( cut == "�٪A" ) {
                                    walk -> next = new Type ;
                                    walk = walk -> next ;
                                    walk -> num = 3 ;
                                    walk -> next = NULL ;
                                } // else if

                                else { // ��|
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

        void Write_credit() { // �w�׾Ǥ��ƤζZ�����~�һݾǤ���
            string fileName = "�Ǥ���.txt" ;
            fstream outfile ;
            bool allCom = false, com0 = false, com1 = false, com2 = false ; // �v �H ��
            bool com3 = false, com4 = false, com5 = false ; // �v ��� ��L
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
            outfile << "�Z�����~�һݾǤ�:" << GRADUATIONSUM << "/" << sGraduation << endl ;
            outfile << "�t�W���׾Ǥ�:" << DEPARTMENTNEED << "/" << sDepartmentNeed << endl ;
            outfile << "�q�Ѱ�¦�Ǥ�:" << COMMENSENCE << "/" << sCommence << endl ;
            if ( sCommence < 14 ) {
                if ( allCom )
                    outfile << "    ��Ǥ֭פ@��!" << endl ;
                else {
                    if ( !com0 )
                        outfile << "    �v���|���ײ�!" << endl ;
                    if ( !com1 )
                        outfile << "    �H���|���ײ�!" << endl ;
                    if ( !com2 )
                        outfile << "    �����|���ײ�!" << endl ;
                    if ( !com3 )
                        outfile << "    ���v�|���ײ�!" << endl ;
                    if ( !com4 )
                        outfile << "    ��Ǩ�󳣩|���ײ�!" << endl ;
                    if ( !com5 )
                        outfile << "    ��L�|���ײ�!" << endl ;
                } // else
            } // if

            outfile << "�q�ѩ����Ǥ�:" << COMMENSENCEPLUS << "/" << sCommencePlus << endl ;
            outfile << "    �Ѿǭײ�" << sora << "��\n" ;
            outfile << "    �H�ǭײ�" << hito << "��\n" ;
            outfile << "    ���ǭײ�" << mono << "��\n" ;
            outfile << "    �ھǭײ�" << boku << "��\n" ;
            outfile << "��׾Ǥ�:" << CHOISECREDIT << "/" << sChoiseCredit << endl ;
            outfile << "�򥻪���Ǥ�:" << BASEMENT << "/" << sBasement << endl ;
            if ( english1 == 0 )
                outfile << "    �j�@�^��|�t���!\n" ;
            else if ( english1 == 1 )
                outfile << "    �j�@�^��|�t�@��!\n" ;

            if ( listening == 0 )
                outfile << "    �j�@�^ť�|�t���!\n" ;
            else if ( listening == 1 )
                outfile << "    �j�@�^ť�|�t���!\n" ;

            if ( english2 == 0 )
                outfile << "    �j�G�^��|�t���!\n" ;
            else if ( english2 == 1 )
                outfile << "    �j�G�^��|�t�@��!\n" ;

            if ( serve == 0 )
                outfile << "    �٪A�|�t���!\n" ;
            else if ( serve == 1 )
                outfile << "    �٪A�|�t�@��!\n" ;

            if ( PE < 6 )
                outfile << "    ��|�|�t" << 6-PE << "��!\n" ;

            outfile.close() ;
        } // Write_credit()

        void Write_course() { // �w�ײ߽ҵ{
            fstream outfile ;
            string fileName = "Passed Courses.txt" ;
            outfile.open( fileName.c_str(), fstream :: out | ios :: trunc ) ;
            if ( !outfile.is_open() )
                cout << "fuck" ;

            for ( int i = 0 ; i < datas.size() ; i++ ) {
                if ( datas[i].typeHead -> num == 0 )
                    outfile << "�t����" ;

                else if ( datas[i].typeHead -> num == 1 ) {
                    outfile << "�q�Ѱ�¦ " ;
                    TypePtr walk = datas[i].typeHead -> next ;
                    if ( walk -> num == 0 )
                        outfile << "�v��" ;
                    else if ( walk -> num == 1 )
                        outfile << "�H��" ;
                    else if ( walk -> num == 2 )
                        outfile << "����" ;
                    else if ( walk -> num == 3 )
                        outfile << "���v" ;
                    else if ( walk -> num == 4 )
                        outfile << "���" ;
                    else if ( walk -> num == 5 )
                        outfile << "��L" ;
                } // else if

                else if ( datas[i].typeHead -> num == 2 ) {
                    outfile << "�q�ѩ��� " ;
                    TypePtr walk = datas[i].typeHead -> next ;
                    if ( walk -> num == 0 )
                        outfile << "��" ;
                    else if ( walk -> num == 1 )
                        outfile << "�H" ;
                    else if ( walk -> num == 2 )
                        outfile << "��" ;
                    else if ( walk -> num == 3 )
                        outfile << "��" ;
                } // else if

                else if ( datas[i].typeHead -> num == 3 ) {
                    outfile << "��� " ;
                    TypePtr walk = datas[i].typeHead -> next ;
                    if ( walk -> num == 0 )
                        outfile << "�ۥ�" ;
                    else if ( walk -> num == 1 )
                        outfile << "�t" ;
                } // else if

                else if ( datas[i].typeHead -> num == 4 ) {
                    outfile << "�򥻪��� " ;
                    TypePtr walk = datas[i].typeHead -> next ;
                    if ( walk -> num == 0 )
                        outfile << "�j�@�^��" ;
                    else if ( walk -> num == 1 )
                        outfile << "�j�@�^ť" ;
                    else if ( walk -> num == 2 )
                        outfile << "�j�G�^��" ;
                    else if ( walk -> num == 3 )
                        outfile << "�٪A" ;
                    else if ( walk -> num == 4 )
                        outfile << "��|" ;
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
            cout << "�Z�����~�һݾǤ�:" << GRADUATIONSUM << "/" << sGraduation << endl ;
            cout << "�t�W���׾Ǥ�:" << DEPARTMENTNEED << "/" << sDepartmentNeed << endl ;
            cout << "�q�Ѱ�¦�Ǥ�:" << COMMENSENCE << "/" << sCommence << endl ;
            cout << "�q�ѩ����Ǥ�:" << COMMENSENCEPLUS << "/" << sCommencePlus << endl ;
            cout << "��׾Ǥ�:" << CHOISECREDIT << "/" << sChoiseCredit << endl ;
            cout << "�򥻪���Ǥ�:" << BASEMENT << "/" << sBasement << endl ;
        } // Show()

        bool IsEmpty() {
            return datas.empty() ;
        } // IsEmpty()

        void Debug() {
            cout << datas.size() << endl ;
            //cout << datas[1].typeHead -> num << " " << datas[1].name << " " << datas[1].credit << endl ;
        } // Debug()
} ; // class DataVector


