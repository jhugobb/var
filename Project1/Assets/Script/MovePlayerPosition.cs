using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MovePlayerPosition : MonoBehaviour {

    private Vector3 newPosition;
    private Vector3 direction;
    private double distance;

    public int playerSpeed;

    public float CLOSE_ENOUGH = 0.06f;


    // Use this for initialization
    void Start () {
        playerSpeed = 4;
	}
	
	// Update is called once per frame
	void Update () {
        if (distance > CLOSE_ENOUGH)
        {
            transform.position = transform.position + direction * playerSpeed * Time.deltaTime;
            direction = newPosition - transform.position;
            direction.Normalize();
            distance = Vector3.Distance(transform.position, newPosition);
        }
    }

    public void Teleport    ()
    {
        RaycastHit hit;

        if (Physics.Raycast(transform.position, Camera.main.transform.forward, out hit, Mathf.Infinity))
        {
            newPosition.Set(hit.point.x, transform.position.y, hit.point.z);
            
            direction.Normalize();
            distance = Vector3.Distance(transform.position, newPosition);

            // Do something with the object that was hit by the raycast.
        }

    }

    public void OnCollisionEnter(Collision collision)
    {
        distance = 0;
    }
}
