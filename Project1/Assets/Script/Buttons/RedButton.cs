using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RedButton : MonoBehaviour {


    private bool isActivated;
    private float spinForce = 20;

    Door door;
    // Use this for initialization
    void Start () {
        isActivated = false;
        Renderer myRenderer = GetComponent<Renderer>();
        myRenderer.material.color = Color.red;

        door = GameObject.FindGameObjectWithTag("redDoor1").GetComponent(typeof(Door)) as Door;
    }
	
	// Update is called once per frame
	void Update () {
		if (isActivated)
        {
            transform.Rotate(0, spinForce * Time.deltaTime, 0);
        }
	}

    public void Toggle()
    {
        if (!isActivated)
        {
            door.OpenDoor();
            isActivated = true;

        } else
        {
            door.CloseDoor();
            isActivated = false;
        }
    }
}
