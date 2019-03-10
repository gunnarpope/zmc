# Zero Messaging Coin
Author: gunnarpope on 3/10/19

## To run:

Start the proxy

    [terminal 1]
    ./msgproxy

Start three publishers on accounts: account1 account2 account3

    [terminal 2]
    /zmc $ ./msgpub account1 "message acct 1"

    [terminal 3]
    /zmc $ ./msgpub account2 "message acct 2"

    [terminal 4]
    /zmc $ ./msgpub account3 "message acct 3"

In a new terminal, subscribe only to account1 and account3 data:

    /zmc $ ./msgsub account1 account3
    Collecting Data from Publishers...

    account1: message acct 1
    account3: message acct 3
    account1: message acct 1
    account3: message acct 3
    account1: message acct 1
    account3: message acct 3
    account1: message acct 1
    account3: message acct 3
