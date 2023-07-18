
// simple parking lot code using stack , queue through linked list and hashing  

#include <iostream>
using namespace std;
class parking_lot
{
private:

    struct car
    {
        int lisc_plate;
        car* next;
    };

    car* shead;       // Stack
    car* lhead;       // List or Queue
    car* vhead[2];    // HASH table 
    int decal;
    int count;

public:

    parking_lot()
    {
        decal = 123;
        count = 0;
        shead = NULL; 
        lhead = NULL;
        for (int i = 0; i < 2; i++)
        {
            vhead[i] == NULL;
        }
    }
     
    // function for parking VIP's car (HASHING)

    void VIP()
    {
            car* new_car = new car();
            cout << "\n\n Enter the lisence number of your car : ";
            cin >> new_car->lisc_plate;
            new_car->next = NULL;

            // HASHING through Chaining 

            int index = new_car->lisc_plate % 2;
            if (vhead[index] == NULL)
            {
                vhead[index] = new_car;
            }
            else
            {
                car* temp = vhead[index];
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = new_car;
            }
    }
  
    // The function of counting the cars entering in parking lot ( STACK )

    void stack(int lisc)
    {
        car* temp = new car();
        temp->lisc_plate = lisc;
        temp->next = shead;
        shead = temp;

    }

    // Function to check decal number of cars entering in parking lot

    bool decal_check()
    {
        int dec;
        cout << "\n\t Enter the decal number : ";
        cin >> dec;
        if (dec == decal)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Checking the limit of cars entering 

    void car_entry(int lisc)
    {
        if (count < 10)
        {
            ++count;
            stack(lisc);                                 // if car entered are less than n then enter in stack LIFO
        }
        else
        {
            cout << "\n As parking lot is full already so this car is parked in waiting area " << endl;
            list(lisc);                                 // if parking lot limit has reached then umcoming cars should enter in list 
                                                        // in the form of FIFO
        }
    }
 
    // Fuction of cars entering in waiting area ( LIST)

    void list(int lisc)
    {
        car* temp1 = new car();
        temp1 = lhead;
        car* temp = new car();
        temp->lisc_plate = lisc;
        temp->next = NULL;
        if (lhead == NULL)
            lhead = temp;
        else
        {
            while (temp1->next != NULL)
            {
                temp1 = temp1->next;
            }
            temp1->next = temp;
        }

    }

    // Function for cars to leave the parking lot
    
    void del_park()
    {
        count--;
        if (shead == NULL)
        {
            cout << " parking lot is empty ! \n NO CARS TO REMOVE \n ";
            return;
        }
        else
        {
            car* temp = new car();
            temp = shead;
            shead = shead->next;
            delete temp;
        }
    }

    // When a car leaves from parking lot one car from waiting area will enter in parking lot

    void replace()
    {
        if (lhead == NULL)
        {
            cout << " EMPTY ! ";
            return;
        }
        car* temp = new car();
        if (lhead->next == NULL)
        {
            
            temp->lisc_plate = lhead->lisc_plate;
            temp->next = shead;
            shead = temp;
            lhead=NULL;
            return;
        }

        // Find the second last car

        car* second_last = lhead;
        while (second_last->next->next != NULL) 
        {
            second_last = second_last->next;
        }
        temp->lisc_plate = second_last->next->lisc_plate;
        temp->next = shead;
        shead = temp;


        // Delete last car

        delete (second_last->next);

        // Change next of second last

        second_last->next = NULL;

        
    }
    // you can also make only one function for displaying parking lot, waiting area and VIP area
    //_______________________________________________________________________________________________________________________________
    //____________________________________________ DISPLAY FUNCTIONS_________________________________________________________________
    //_______________________________________________________________________________________________________________________________

    // parking Lot

    void display_parking_lot()
    {
        cout << " \n\t\t\t /PARKING AREA/ \t\t\t" << endl;
        car* temp = new car();
        if (shead == NULL)
        {
            cout << "\n PARKING LOT IS  EMPTY \n";
            return;
        }
        temp = shead;
        while (temp!=NULL)
        {
            cout << " " << temp->lisc_plate;
            temp = temp->next;
        }
    }

    // waiting area 

    void display_waiting_lot()
    {
        cout << " \n\t\t\t\ /WAITING AREA/ \t\t\t" << endl;
        car* temp = new car();
        temp = lhead;
        if (lhead == NULL)
        {
            cout << "\n WAITING AREA IS EMPTY\n";
            return;
        }
        else
        {
            while (temp != NULL)
            {
                cout << " " << temp->lisc_plate;
                temp = temp->next;
            }
        }
    }

    // VIP slots 

    void print_VIP()
    {

        cout << "\t\t\t /VIP SLOTS/ " << endl;
        for (int i = 0; i < 2; i++)        // hash table
        {
            if (vhead[i] == NULL)
            {
                cout << i;             // print index
            }
            else
            {
                cout << i;
                car* temp = new car();
                temp = vhead[i];
                while (temp != NULL)
                {
                    cout << "-->" << temp->lisc_plate;
                    temp = temp->next;
                }

            }
            cout << endl;

        }
    }

};
int main()
{

    cout << "\n1.\tAdding Car in Parking Lot\n2.\tRemoving Car from Parking Lot\n3.\tAdding Car in VIP Slot\n4.\tDisplay Parking Lot\n5.\tDisplay Waiting Area\n6.\tDisplay VIP Area\n7.\tStop" << endl << endl;
    cout << "\n________________________________________________________________________________________________________________________\n" << endl;

    cout << " ONLY DECAL NUMBER OF 123 CAN PARK CARS IN THIS PARKING LOT SYSTEM ";
    cout << endl;

    parking_lot p;
    int lisc;               // enter the lisc number of your car
    int choice;      
    do
    {
        cout << "\t_____________________________________________" << endl;
        cout << "\n\t\t Enter your choice: ";
        cin >> choice;
        cout << "\t_____________________________________________" << endl;

        switch (choice)
        {
        case 1:
        {
            // adding car to parking lot or waiting area
            if (p.decal_check())
            {
                cout << "\n You can enter your car in parking lot !! \n\n";
                cout << "\n Enter your lisc plate : ";
                cin >> lisc;
                p.car_entry(lisc);

            }
            else
            {
                cout << "\n You can not enter your car in parking lot !! \n\n";

            }
            break;
        }

        case 2:
        {
            // removing car from parking lot
            p.del_park();
            // if waiting area is not empty only then we can replace cars from waiting area to parking lot
            cout << endl << "\n Car Removed from Parking Lot ! \n Car from Waiting Area is parked in Parking Lot Now\n" << endl;
            p.replace();
            break;
        }
        case 3:
        {
            // any number of cars with decal number of 1001 can enter the VIP parking slot
            cout << "\n ONLY DECAL NUMBER OF 1001 CAN ENTER THE AREA OF VIPs IN PARKING LOT \n";
            int VIP_decal;

            cout << "\n Enter your DECAL number : ";
            cin >> VIP_decal;
            if (VIP_decal == 1001)
            {
                p.VIP();

            }
            else
            {
                cout << "\n Sorry you can't park your car in this area \n";
            }
            break;
        }
        case 4:
        {

            cout << "\n________________________________________________________________________________________________________________________" << endl;
            p.display_parking_lot();
            cout << "\n________________________________________________________________________________________________________________________" << endl;
            break;
        }
        case 5:
        {
            cout << "\n________________________________________________________________________________________________________________________" << endl;
            p.display_waiting_lot();
            cout << "\n________________________________________________________________________________________________________________________" << endl;
            break;
        }
        case 6:
        {
            cout << "\n________________________________________________________________________________________________________________________" << endl;
            p.print_VIP();
            cout << "\n________________________________________________________________________________________________________________________" << endl;
            break;
        }
        case 7:
        {
            cout << " STOP ! YOU ARE EXITING FROM PARKING LOT "<<endl;
            break;
        }

        default:
        {
            cout << " Invalid case! Enter again ! ";
            break; 

        }

        }
    }while (choice!=7);
    
  
}
