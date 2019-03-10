//  Asynch. Message Publisher 
//  Usage: $ ./msgpub account1 "message acct 1"
//  connects to PUB socket to tcp://*:5556
//  Publishes text data from terminal input 

#include "zhelpers.h"
#include "unistd.h"

int main (int argc, char *argv[])
{
    //  Prepare our context and publisher
    void *context = zmq_ctx_new ();
    void *publisher = zmq_socket (context, ZMQ_PUB);
    int rc = zmq_connect(publisher, "tcp://localhost:5556");
    assert (rc == 0);

    char *account= (argc > 1)? argv [1]: "account1";
    char *message= (argc > 1)? argv [2]: "no message";


    char update [64];
    sprintf(update, "Startup\n");
    s_send (publisher, update);

while(1){            //  Send message to all subscribers
    sprintf (update, "%s: %s\n", account,message);
    s_send (publisher, update);
    sleep(1);
  }

    zmq_close (publisher);
    zmq_ctx_destroy (context);
    return 0;
}
