#include <assert.h>

#include <stdio.h>

#include <ctype.h>

#include <string.h>




enum event {SCANNING_CARD, CARD_OKAY, CARD_FAKE, ENTER_IN,APPLICATION_ERROR, WAIT
}; //possible event that can happen due to the card usage


int n = 0; //the initial amount of passangers who got into the subway 


enum state {STAY, CARD_PROCESSING, JUST_ENTER, GO_OUT, ALLOWED, ERROR} ; //all possible feedback that the machine can give

enum state current = STAY; 



enum state getStateByEvent (enum event e) {
    if (e ==APPLICATION_ERROR) return ERROR; //for any system error cases



    switch (current)
    {
    case STAY:
        if (e == SCANNING_CAR) return CARD_PROCESSING;
        break;


    case CARD_PROCESSING:
        if (e == CARD_OKAY) return JUST_ENTER;
        if (e == CARD_FAKE) return GO_OUT;
        break;


    case JUST_ENTER:
        if (e == ENTER_IN) return ALLOWED;
        break;   


    case GO_OUT:
        if (e == WAIT) return STAY;
        break;     
        
        
    case ALLOWED:
        if (e == WAIT) return STAY;
        break; 


    default:
        return STAY;
        break;


    }
    return current; 
}

const char* getStateLabel() // this is to return corresponding texts for each event happening during the process 
{
    switch (current)
    {
    case STAY:
        return "Can you please scan your document";
        break;


    case CARD_PROCESSING:
        return "Please, wait for some minutes";
        break;


    case JUST_ENTER:
        return "Congratulations, you got an access";
        break;   


    case GO_OUT:
        return "Stop, you did not get an access";
        break;      


    case ALLOWED:
        return "Please , enter";
        break; 
    default:

        return "ERROR";
        break;
    }
}

int main() {
  
    printf("%s\n\n", "Process with valid card:");
    printf("%s\n", getStateLabel());

    current = getStateByEvent(SCANNING_CAR);
     printf("%s\n", getStateLabel());

    current = getStateByEvent(CARD_OKAY);
     printf("%s\n", getStateLabel());

    current = getStateByEvent(ENTER_IN);
     printf("%s\n", getStateLabel()); 

    if (current == ALLOWED) {
    n++;
    }

    current = getStateByEvent(WAIT);
     printf("%s\n\n", getStateLabel());
     

    
     printf("%s\n\n","Process with invalid card:");
     printf("%s\n", getStateLabel());

    current = getStateByEvent(SCANNING_CAR);
     printf("%s\n", getStateLabel());

    current = getStateByEvent(CARD_FAKE);
     printf("%s\n", getStateLabel());

    current = getStateByEvent(WAIT);
     printf("%s\n\n", getStateLabel());
    
     // process with invalid document
     

    
     printf("%s\n\n","Process with a system error:");
     printf("%s\n", getStateLabel());

    current = getStateByEvent(SCANNING_CAR);
     printf("%s\n", getStateLabel());

    current = getStateByEventGLOBAL_ERROR);
     printf("%s\n", getStateLabel());

    current = getStateByEvent(WAIT);
     printf("%s\n\n", getStateLabel());

     // global system error
     

    
    printf("Total number of passengers who succesfully got in the subway: %d\n", n);//number of passenger in it
    return 0;
}

