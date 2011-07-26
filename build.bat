dblproto CCtest.dbl CCutils.dbc Encryption.dbc
dbl -d -qalign -o CCtest CCtest.dbl CCutils.dbc Encryption.dbc
dblink -d CCtest WND:tklib.elb
