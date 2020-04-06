#include<stdio.h>
#include<windows.h>
void add_contact();
void search_contact();
void delete_contact();
void view_all_contact();
void main()
{
    system("cls");
    printf("\t\t\t\t\t#======================================#\n");
    printf("\t\t\t\t\t#                                      #\n");
    printf("\t\t\t\t\t#  **********************************  #\n");
    printf("\t\t\t\t\t#  *  PHONE BOOK MANAGEMENT SYSTEM  *  #\n");
    printf("\t\t\t\t\t#  **********************************  #\n");
    printf("\t\t\t\t\t#______________________________________#\n");
    printf("\t\t\t\t\t#                                      #\n");
    printf("\t\t\t\t\t#  Please Select an Option...          #\n");
    printf("\t\t\t\t\t#                                      #\n");
    printf("\t\t\t\t\t#     1. Add Contact                   #\n");
    printf("\t\t\t\t\t#     2. Search Contact                #\n");
    printf("\t\t\t\t\t#     3. Delete Contact                #\n");
    printf("\t\t\t\t\t#     4. View All Contact              #\n");
    printf("\t\t\t\t\t#     5. Exit                          #\n");
    printf("\t\t\t\t\t#                                      #\n");
    printf("\t\t\t\t\t#======================================#\n");
    printf("\t\t\t\t\t   ..............");
    int option;
    scanf("%d",&option);

    switch(option)
    {
    case 1:
        add_contact();
        break;
    case 2:
        search_contact();
        break;
    case 3:
        delete_contact();
        break;
    case 4:
        view_all_contact();
        break;
    case 5:
        exit(0);
    default:
        main();
    }
}
void add_contact()
{
    FILE *fp;
    char name[100],mob[100];
    int option;
    fp=fopen("contact.txt","a+");
    system("cls");
    printf("\t\t\t\t\t#======================================#\n");
    printf("\t\t\t\t\t#                                      #\n");
    printf("\t\t\t\t\t#  **********************************  #\n");
    printf("\t\t\t\t\t#  *  PHONE BOOK MANAGEMENT SYSTEM  *  #\n");
    printf("\t\t\t\t\t#  **********************************  #\n");
    printf("\t\t\t\t\t#______________________________________#\n");
    printf("\t\t\t\t\t#                                      #\n");
    printf("\t\t\t\t\t#             ADD CONTACT              #\n");
    printf("\t\t\t\t\t#             -----------              #\n");
    printf("\t\t\t\t\t#                                      #\n");
    printf("\t\t\t\t\t#\tContact Name    : ");
    scanf("%s",name);
    printf("\t\t\t\t\t#\tContact No.     : " );
    scanf("%s",mob);
    fprintf(fp,"%s %s\n",name,mob);
    fclose(fp);
    printf("\t\t\t\t\t#                                      #\n");
    printf("\t\t\t\t\t#                                      #\n");
    printf("\t\t\t\t\t#                                      #\n");
    printf("\t\t\t\t\t#  PRESS ANY KEY TO GO MAIN MENU...    #\n");
    printf("\t\t\t\t\t#                                      #\n");
    printf("\t\t\t\t\t#======================================#\n");
    getch();
    main();
}
void search_contact()
{
    FILE *fp;
    char name[100],name1[100],mob[100];
    fp=fopen("contact.txt","r");
    system("cls");
    printf("\t\t\t\t\t#======================================#\n");
    printf("\t\t\t\t\t#                                      #\n");
    printf("\t\t\t\t\t#  **********************************  #\n");
    printf("\t\t\t\t\t#  *  PHONE BOOK MANAGEMENT SYSTEM  *  #\n");
    printf("\t\t\t\t\t#  **********************************  #\n");
    printf("\t\t\t\t\t#______________________________________#\n");
    printf("\t\t\t\t\t#                                      #\n");
    printf("\t\t\t\t\t#             SEARCH CONTACT           #\n");
    printf("\t\t\t\t\t#             --------------           #\n");
    printf("\t\t\t\t\t#                                      #\n");
    printf("\t\t\t\t\t#\tEnter Name    : ");
    scanf("%s",name);
    while(fscanf(fp,"%s %s",name1,mob)!=EOF)
    {
        if(strcmp(name,name1)==0)
        {
            printf("\t\t\t\t\t#______________________________________#\n");
            printf("\t\t\t\t\t#                                      #\n");
            printf("\t\t\t\t\t#  Your Searched data...               #\n");
            printf("\t\t\t\t\t#                                      #\n");
            printf("\t\t\t\t\t#\tContact Name    : %s\n",name1);
            printf("\t\t\t\t\t#\tContact NO.    : %s\n",mob);
        }
    }
    fclose(fp);
    printf("\t\t\t\t\t#                                      #\n");
    printf("\t\t\t\t\t#                                      #\n");
    printf("\t\t\t\t\t#                                      #\n");
    printf("\t\t\t\t\t#  PRESS ANY KEY TO GO MAIN MENU...    #\n");
    printf("\t\t\t\t\t#                                      #\n");
    printf("\t\t\t\t\t#======================================#\n");
    getch();
    main();
}
void delete_contact()
{
    FILE *fp,*fp1;
    char name[100],name1[100],mob[100];
    fp=fopen("contact.txt","r+");
    fp1=fopen("temp.txt","w");
    system("cls");
    printf("\t\t\t\t\t#======================================#\n");
    printf("\t\t\t\t\t#                                      #\n");
    printf("\t\t\t\t\t#  **********************************  #\n");
    printf("\t\t\t\t\t#  *  PHONE BOOK MANAGEMENT SYSTEM  *  #\n");
    printf("\t\t\t\t\t#  **********************************  #\n");
    printf("\t\t\t\t\t#______________________________________#\n");
    printf("\t\t\t\t\t#                                      #\n");
    printf("\t\t\t\t\t#             DELETE CONTACT           #\n");
    printf("\t\t\t\t\t#             --------------           #\n");
    printf("\t\t\t\t\t#                                      #\n");
    printf("\t\t\t\t\t#                                      #\n");
    printf("\t\t\t\t\t#\tEnter Name : ");
    scanf("%s",name);
    while(fscanf(fp,"%s %s",name1,mob)!=EOF)
    {
        if(strcmp(name,name1)==0)
        {
            continue;
        }
        fprintf(fp1,"%s %s\n",name1,mob);
    }
    fclose(fp);
    fclose(fp1);
    fp=fopen("contact.txt","w");
    fp1=fopen("temp.txt","r");
    while(fscanf(fp1,"%s %s",name1,mob)!=EOF)
    {
        fprintf(fp,"%s %s\n",name1,mob);
    }
    fclose(fp);
    fclose(fp1);
    remove("temp.txt");
    printf("\t\t\t\t\t#                                      #\n");
    printf("\t\t\t\t\t#       OPERATION DONE!...             #\n");
    printf("\t\t\t\t\t#                                      #\n");
    printf("\t\t\t\t\t#                                      #\n");
    printf("\t\t\t\t\t#  PRESS ANY KEY TO GO MAIN MENU...    #\n");
    printf("\t\t\t\t\t#                                      #\n");
    printf("\t\t\t\t\t#======================================#\n");
    getch();
    main();
}
void view_all_contact()
{
    FILE *fp;
    char name1[100],mob[100];
    fp=fopen("contact.txt","r");
    system("cls");
    printf("\t\t\t\t\t#======================================#\n");
    printf("\t\t\t\t\t#                                      #\n");
    printf("\t\t\t\t\t#  **********************************  #\n");
    printf("\t\t\t\t\t#  *  PHONE BOOK MANAGEMENT SYSTEM  *  #\n");
    printf("\t\t\t\t\t#  **********************************  #\n");
    printf("\t\t\t\t\t#______________________________________#\n");
    printf("\t\t\t\t\t#                                      #\n");
    printf("\t\t\t\t\t#             ALL CONTACT              #\n");
    printf("\t\t\t\t\t#             -----------              #\n");
    printf("\t\t\t\t\t#                                      #\n");
    printf("\t\t\t\t\t#    Contact Name      Contact No.     #\n");
    printf("\t\t\t\t\t#    ------------      -----------     #\n");
    printf("\t\t\t\t\t#                                      #");
    while(fscanf(fp,"%s %s",name1,mob)!=EOF)
    {
        printf("\n\t\t\t\t\t#\t%s",name1);
        printf("\t\t%s",mob);
    }
    fclose(fp);
    printf("\n\t\t\t\t\t#                                      #\n");
    printf("\t\t\t\t\t#                                      #\n");
    printf("\t\t\t\t\t#  PRESS ANY KEY TO GO MAIN MENU...    #\n");
    printf("\t\t\t\t\t#                                      #\n");
    printf("\t\t\t\t\t#======================================#\n");
    getch();
    main();
}



