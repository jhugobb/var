using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class WhiteButton : MonoBehaviour {

    private int activeColor;
    private float spinForce = 150;
    private Renderer rend;
    private AudioSource source;
    public AudioClip shootSound;
    public bool fix = true;

    Door door;

    // Use this for initialization
    void Start () {
        activeColor = 0;
        rend = gameObject.GetComponent<Renderer>();
        rend.material.color = Color.gray;
        source = GameObject.FindGameObjectWithTag("audio").GetComponent<AudioSource>();
    }
	
	// Update is called once per frame
	void Update () {
        if (activeColor != 0)
        {
            transform.Rotate(0, spinForce * Time.deltaTime, 0);
        }
    }

    public void Toggle()
    {
        if (fix)
        {
            source.PlayOneShot(shootSound, 1f);
            if (activeColor == 0) //white -> red
            {
                activeColor = 1;
                door = GameObject.FindGameObjectWithTag("red" + gameObject.tag).GetComponent(typeof(Door)) as Door;
                door.OpenDoor();
                gameObject.GetComponent<Renderer>().material.color = Color.red;
                rend.material.color = Color.red;
            }
            else if (activeColor == 1) //red -> blue
            {
                door.CloseDoor();
                activeColor = 2;
                door = GameObject.FindGameObjectWithTag("blue" + gameObject.tag).GetComponent(typeof(Door)) as Door;
                door.OpenDoor();
                rend.material.color = Color.blue;
            }
            else if (activeColor == 2) // blue -> yellow
            {
                door.CloseDoor();
                activeColor = 3;
                door = GameObject.FindGameObjectWithTag("yellow" + gameObject.tag).GetComponent(typeof(Door)) as Door;
                door.OpenDoor();
                rend.material.color = Color.yellow;
            }
            else // yellow -> white
            {
                door.CloseDoor();
                activeColor = 0;
                door = null;
                rend.material.color = Color.gray;

            }
        }
        else
        {
            fix = true;
        }
        
    }
}
