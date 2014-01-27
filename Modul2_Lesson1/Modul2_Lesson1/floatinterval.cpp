struct FloatInterval 
{ 
    FloatInterval(); 
    FloatInterval(float start, float end); 
    float midpoint(); 
    float a; 
    float b; 
}; 

FloatInterval::FloatInterval() 
{ 
    a = 0.0f;   
    b = 0.0f;  
}

FloatInterval::FloatInterval(float start, float end) 
{ 
    a = start;   
    b = end;  
} 

float FloatInterval::midpoint() 
{ 
    // return the midpoint between a and b.
    return(a + b) * 0.5; 
}