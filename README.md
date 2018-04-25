"# i2cSecuredTransfer" 

Author: Drew Applegath
Updated: 04/17/2018

Sender - 
	Sends a string over an I2C communication that has data encrypted with a shared key to another device running the client program. 

Receiver -

	Receives data from the I2C bus and decrypts it and checks for the key to be encrypted in the data. The key needs to be shared beforehand.

** Unit is made for running on two arduino Unos, and will send data every half second. 