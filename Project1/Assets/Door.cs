using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Door : MonoBehaviour {

	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		
	}

    public void OpenDoor()
    {
        transform.Translate(0, 100, 0);
    }

    public void CloseDoor()
    {
        transform.Translate(0, -100, 0);
    }
}
