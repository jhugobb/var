using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BlackButton : MonoBehaviour {

    private Vector3 lastPosition;
    private float spinForce = 150;

    // Use this for initialization
    void Start () {
        lastPosition = new Vector3(58.5f, 1, -66.1f);
	}
	
	// Update is called once per frame
	void Update () {
        transform.Rotate(0, spinForce * Time.deltaTime, 0);
    }

    public void Toggle()
    {
        GameObject player = GameObject.FindGameObjectWithTag("Player");
        Vector3 playerPosition = player.transform.position;
        player.transform.position = lastPosition;
        lastPosition = playerPosition;
    }
}
