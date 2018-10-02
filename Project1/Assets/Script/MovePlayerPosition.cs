using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MovePlayerPosition : MonoBehaviour {

	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
        
    }

    public void Teleport    ()
    {
        RaycastHit hit;

        if (Physics.Raycast(transform.position, Camera.main.transform.forward, out hit, Mathf.Infinity))
        {
            Vector3 pos = new Vector3();
            pos.Set(hit.point.x, transform.position.y, hit.point.z);
            transform.position = pos;

            // Do something with the object that was hit by the raycast.
        }

    }
}
