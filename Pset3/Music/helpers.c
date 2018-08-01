// Helper functions for music

#include <cs50.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int nume = fraction[0] - '0';
    int deno = fraction[2] - '0';
    int res = nume * (8 / deno);
    return res;
}

// Calculates frequency (in Hz) of a note

int frequency(string note)
{

    // calculating 2 * (1 / 12) for flats and sharps notes
    double us;
    double a = 1;
    double b = 12;
    us = a / b;
    double power = pow(2, us);

// calculating the hertz of specific notes on 4th octave
    int fourthOctave;

    if (note[0] == 'A')
    {
        fourthOctave = 440;
    }

    if (note[0] == 'B')
    {
        double bfourthOctave = 440 * pow(power, 2);
        fourthOctave = round(bfourthOctave);
    }

    if (note[0] == 'G')
    {
        double gfourthOctave = 440 / pow(power, 2);
        fourthOctave = round(gfourthOctave);
    }

    if (note[0] == 'F')
    {
        double ffourthOctave = 440 / pow(power, 4);
        fourthOctave = round(ffourthOctave);
    }

    if (note[0] == 'E')
    {
        double efourthOctave = 440 / pow(power, 5);
        fourthOctave = round(efourthOctave);
    }

    if (note[0] == 'D')
    {
        double dfourthOctave = 440 / pow(power, 7);
        fourthOctave = round(dfourthOctave);
    }

    if (note[0] == 'C')
    {
        double cfourthOctave = 440 / pow(power, 9);
        fourthOctave = round(cfourthOctave);
    }

    // shifting the note's octave from 4th octave

    // if the note is a flat one
    if (note[1] == 'b')
    {
        // convert octave to int
        int octave = note[2] - '0' ;

        // first multiply A4's hertz 440 with octave  and divide it 2*(1/12) to find the flat
        if (octave < 4)
        {
            double hertz = (fourthOctave / pow(2, (4 - octave))) / power;
            int r = round(hertz);
            return r;
        }
        else
        {
            double hertz = (fourthOctave * pow(2, (octave - 4))) / power;
            int r = round(hertz);
            return r;
        }
    }

    // if note is sharp one
    else if (note[1] == '#')
    {
        int octave = note[2] - '0' ;
        // first multiply A4's hertz 440 with octave  and multiply it 2*(1/12) to find the sharp note

        if (octave < 4)
        {
            double hertz = (fourthOctave / pow(2, (4 - octave))) * power;
            int r = round(hertz);
            return r;
        }
        else
        {
            double hertz = (fourthOctave * pow(2, (octave - 4))) * power;
            int r = round(hertz);
            return r;
        }

    }

    // if it is a regular note
    else
    {
        int octave = note[1] - '0' ;
        if (octave < 4)
        {
            int hertz = fourthOctave / pow(2, (4 - octave));
            int r = round(hertz);
            return r;
        }
        else
        {
            int hertz = fourthOctave * pow(2, (octave - 4));
            int r = round(hertz);
            return r;
        }
    }

}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (s == "\n" || s == "\r" || s == "\r\n" || s[0] == '\0')
    {
        return true;
    }
    return false;
}
