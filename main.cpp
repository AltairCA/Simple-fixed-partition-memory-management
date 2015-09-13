#include <QCoreApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    int storage = 3;
    int input = 5;
    int order[input] = {1,2,3,4,5};
    int input_size[input] = {12,20,25,19,10};
    int input_time[input]= {30,25,19,41,18};
    int input_storage[storage] = {10,20,30};
    int total_time_storage[storage] = {0,0,0};
    int returntime = 0;

    QString msg[input];

    int min_index=0;

    for(int x=0;x<input;x++){
        min_index =x;
        for(int y=x;y<input;y++){
            if(input_time[y]<input_time[min_index]){
                min_index = y;
            }


        }
        int temp = input_time[min_index];
        input_time[min_index] = input_time[x];
        input_time[x] = temp;

        temp = input_size[min_index];
        input_size[min_index] = input_size[x];
        input_size[x]= temp;

        temp = order[min_index];
        order[min_index] = order[x];
        order[x] = temp;


    }

    //int current_process=0;
    int current_storage = 0;
    for(int x=0;x<input;x++){

        for(int y=current_storage;y<=storage;y++){
            if(storage==y){
                current_storage=0;
                y=0;
            }else{
                current_storage = y;
            }
            if(input_size[x]<=input_storage[y]){

                    msg[order[x]-1] = "Program "+QString::number(order[x])+" is runs in region "+QString::number(y+1)+" "+QString::number(total_time_storage[y])+" to "+QString::number(total_time_storage[y] + input_time[x]);
                    total_time_storage[y] = total_time_storage[y] + input_time[x];
                    returntime = returntime + total_time_storage[y];
                    if(storage==current_storage){
                        current_storage=0;

                    }else{
                        current_storage++;
                    }
                    break;
            }
        }


    }


    qDebug()<<"Avg turn around time is : "+QString::number(returntime/double(input));

    for(int x=0;x<input;x++){
        qDebug()<<msg[x];
    }

    QCoreApplication a(argc, argv);

    return a.exec();
}
