Stock-Market-Excercise
This exercise is a simple version of a moving average for stock market buying
and selling.

Let's assume we have data for the price of a stock for the
last 30 days. We can compute the average price of the stock for these days
subscripted 0 through 29. Let's choose a \decision metric" of 5 percent. 
Now if the price of the stock on day 30 is more than 5 percent higher than the
average of the last 30 days, then we assume that the stock is doing well, and
we sell shares. If the price is more than 5 percent lower than the average, we
buy.
Then tomorrow we have data for 31 days. We recompute the average
using the data from days subscripted 1 through 30, and continue.
We thus compute a moving average using the data in a window of xed
size, and make decisions based on whether the current price is \high" or
\low" using our value of the decision metric as the denition of high or low.
Basically, this is a standard technique. Use past data to compute a \nor-
mal" value. Compare current data against the normal value, and if it's too
far on the \abnormal" side, then do something.
For this assignment, you have 100 data items that represent the price
of a stock. Read that data into a vector of double values. Then run a
double loop to compute the moving averages of a window of width width
from starting subscripts 0 up to the end. (If the ending subscript is beyong
the length of the vector then quit. That is, if you have 5 data items, and
the window width is 3, the last starting subscript would be 2, and you would
do averages for 0-1-2, 1-2-3, 2-3-4.)
If the LAST VALUE IN YOUR WINDOWis more than decisionMetric
away from the moving average, then issue a BUY or a SELL order as appro-
priate.
(Technically, you would look at the window values and use the NEXT
value to dermine what to do, but that would require being more clever with
subscripts, so don't worry about that. I am sure you could work that out,
but it wouldn't teach you much because it would all be just detail.)
======================

C++ Programming
