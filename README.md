# 1-Pole Noise Filter
This is a repository that implements a 1-Pole noise filter, one of the IIR filter series. It was implemented by excluding floating points for use in microcontrollers.

# NOTE
This code is implemented based on standard integer (stdint).

# Comparison
## steady increase
![steady increase](./steady%20increase.jpg)
## step increase
![step increase](./step%20increase.jpg)
## step decrease
![step decrease](./step%20decrease.jpg)
## inrush situation
![inrush situation](./inrush.jpg)

# HOW TO USE
## initialize
The closer the numerator gets to the denominator value, the greater the response delay. Considering this, you should adjust the values ​​of numerator and denominator.

Conversely, the farther the numerator gets from the denominator value, the closer the data will be to the original.
<pre>
<code>
// The numerator must always be less than the value 2^denominator.
// The value entered in denominator must always be an exponent of 2.
OPF_Initialize(&testObj, 11, 4);
</code>
</pre>

## filterout
<pre>
<code>
value = OPF_Filterout(&testObj, some_data);
</code>
</pre>

# REFERENCE
https://www.infineon.com/dgdl/Infineon-AN2099_PSoC_1_PSoC_3_PSoC_4_and_PSoC_5LP_Single_Pole_Infinite_Impulse_Response_(IIR)_Filters-ApplicationNotes-v11_00-EN.pdf?fileId=8ac78c8c7cdc391c017d072cde6e51bd


https://www.embeddedrelated.com/showarticle/779.php
