# Task
Block access to a certain website. (Linux like OS)

## Using Hosts file
Add the following line to `/etc/hosts`. Note, it requires root access:
~~~bash
0.0.0.0 www.example.com
~~~

Run the following command to see if it worked:
~~~bash
curl www.example.com
~~~

We should get an error similar to this:
~~~bash
curl: (7) Failed to connect to www.example.com port 80: Connection refused
~~~

**Why it worked?**
Using the hosts file, we've **zeroed** the site `www.example.com`.
`0.0.0.0` is used as an invalid IP.



# Conclusion
-
