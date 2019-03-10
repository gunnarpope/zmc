//  Weather update client
//  Connects SUB socket to tcp://localhost:5556
//  Collects weather updates and finds avg temp in zipcode

#include "zhelpers.h"

int main (int argc, char *argv [])
{
    //  Socket to talk to server
    printf ("Collecting Data from Publishers...\n");
    void *context = zmq_ctx_new ();
    void *subscriber = zmq_socket (context, ZMQ_SUB);
    int rc = zmq_connect (subscriber, "tcp://localhost:8100");
    assert (rc == 0);

    //  Subscribe to zipcode, default is NYC, 10001

    if (argc > 1){

        for (int i = 1;i<argc;i++){
          char *filter = argv [i];
          rc = zmq_setsockopt (subscriber, ZMQ_SUBSCRIBE,
                               filter, strlen (filter));
          assert (rc == 0);
        }

    }
    else{
      char *filter = "account1";
      rc = zmq_setsockopt (subscriber, ZMQ_SUBSCRIBE,
                           filter, strlen (filter));
      assert (rc == 0);
    }

    assert (rc == 0);

    while(1){
    //  Process 100 updates
        char *string = s_recv (subscriber);
        printf("%s",string);
        free (string);
}

    zmq_close (subscriber);
    zmq_ctx_destroy (context);
    return 0;
}
